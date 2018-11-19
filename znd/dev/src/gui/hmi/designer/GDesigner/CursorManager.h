

#ifndef H_CURSOR
#define H_CURSOR 
#include "DrawManager.h"
#include <QMap>
#include <QCursor>
#include "Mdi.h"


const int CURSORSIZE = 32;
const int CURSORICONSIZE = 16;

class CursorManager: public Mdi
{
public:
    enum CursorPos{EditPoint,InShape,OtherPos};
    static void SetCursor(CDrawManager::SceneMode mode,const QString& ItemTypeName = QString(),int pos = 0 );
    static void InsertNewTp(const QString& name,const QCursor& cursor);
    void RemoveTp(const QString& name);

    QCursor MakeIconCrossCursor(const QPixmap& pix);
private:
    static QMap<QString,QCursor> s_MapTpCursor;
    CursorManager();
};

CursorManager* UnqCursorMng();

#endif
