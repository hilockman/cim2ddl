

#include "websocketclientwrapper.h"
#include <QtWebSockets/QWebSocket>
#include <QtWebSockets/QWebSocketServer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>



/*!
    \brief Wrapps connected QWebSockets clients in WebSocketTransport objects.

    This code is all that is required to connect incoming WebSockets to the WebChannel. Any kind
    of remote JavaScript client that supports WebSockets can thus receive messages and access the
    published objects.
*/

QT_BEGIN_NAMESPACE

/*!
    Construct the client wrapper with the given parent.

    All clients connecting to the QWebSocketServer will be automatically wrapped
    in WebSocketTransport objects.
*/
WebSocketClientWrapper::WebSocketClientWrapper(QWebSocketServer *server, QObject *parent)
    : QObject(parent)
    , m_server(server)
{
    connect(server, &QWebSocketServer::newConnection,
            this, &WebSocketClientWrapper::handleNewConnection);
}

/*!
    Wrap an incoming WebSocket connection in a WebSocketTransport object.
*/
void WebSocketClientWrapper::handleNewConnection()
{
    emit clientConnected(new WebSocketTransport(m_server->nextPendingConnection()));
}

///////



/*!
    \brief QWebChannelAbstractSocket implementation that uses a QWebSocket internally.

    The transport delegates all messages received over the QWebSocket over its
    textMessageReceived signal. Analogously, all calls to sendTextMessage will
    be send over the QWebSocket to the remote client.
*/



/*!
    Construct the transport object and wrap the given socket.

    The socket is also set as the parent of the transport object.
*/
WebSocketTransport::WebSocketTransport(QWebSocket *socket)
: QWebChannelAbstractTransport(socket)
, m_socket(socket)
{
    connect(socket, &QWebSocket::textMessageReceived,
            this, &WebSocketTransport::textMessageReceived);
}

/*!
    Destroys the WebSocketTransport.
*/
WebSocketTransport::~WebSocketTransport()
{

}

/*!
    Serialize the JSON message and send it as a text message via the WebSocket to the client.
*/
void WebSocketTransport::sendMessage(const QJsonObject &message)
{
    QJsonDocument doc(message);
    m_socket->sendTextMessage(QString::fromUtf8(doc.toJson(QJsonDocument::Compact)));
}

/*!
    Deserialize the stringified JSON messageData and emit messageReceived.
*/
void WebSocketTransport::textMessageReceived(const QString &messageData)
{
    QJsonParseError error;
    QJsonDocument message = QJsonDocument::fromJson(messageData.toUtf8(), &error);
    if (error.error) {
        qWarning() << "Failed to parse text message as JSON object:" << messageData
                   << "Error is:" << error.errorString();
        return;
    } else if (!message.isObject()) {
        qWarning() << "Received JSON message that is not an object: " << messageData;
        return;
    }
    emit messageReceived(message.object(), this);
}

QT_END_NAMESPACE
