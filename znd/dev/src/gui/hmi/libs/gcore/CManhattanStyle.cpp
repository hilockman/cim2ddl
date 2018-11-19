

#include "CManhattanStyle.h"

#include <QApplication>
#include <QComboBox>
#include <QDockWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMenuBar>
#include <QPainter>
#include <QPixmap>
#include <QStatusBar>
#include <QStyleFactory>
#include <QStyleOption>
#include <QToolBar>
#include <QToolButton>


#include <QPixmapCache>
#include <QPainter>
#include <QFileInfo>
#include <QCommonStyle>
#include <qmath.h>




template<typename T, typename F>
typename T::value_type findOr(const T &container, typename T::value_type other, F function)
{
    typename T::const_iterator end = container.end();
    typename T::const_iterator begin = container.begin();

    typename T::const_iterator it = std::find_if(begin, end, function);
    if (it == end)
        return other;
    return *it;
}

template<typename T, typename F>
typename T::value_type findOrDefault(const T &container, F function)
{
    return findOr(container, typename T::value_type(), function);
}

/*template<typename R, typename S, typename T>
auto equal(R (S::*function)() const, T value)
    -> decltype(std::bind<bool>(std::equal_to<T>(), value, std::bind(function, std::placeholders::_1)))
{
    return std::bind<bool>(std::equal_to<T>(), value, std::bind(function, std::placeholders::_1));
}*/

Animation * StyleAnimator::widgetAnimation(const QWidget *widget) const
{
    if (!widget)
        return 0;
    return 0;
}

void Animation::paint(QPainter *painter, const QStyleOption *option)
{
    Q_UNUSED(option)
    Q_UNUSED(painter)
}

void Animation::drawBlendedImage(QPainter *painter, const QRect &rect, float alpha)
{
    if (m_secondaryImage.isNull() || m_primaryImage.isNull())
        return;

    if (m_tempImage.isNull())
        m_tempImage = m_secondaryImage;

    const int a = qRound(alpha*256);
    const int ia = 256 - a;
    const int sw = m_primaryImage.width();
    const int sh = m_primaryImage.height();
    const int bpl = m_primaryImage.bytesPerLine();
    switch (m_primaryImage.depth()) {
    case 32:
        {
            uchar *mixed_data = m_tempImage.bits();
            const uchar *back_data = m_primaryImage.constBits();
            const uchar *front_data = m_secondaryImage.constBits();
            for (int sy = 0; sy < sh; sy++) {
                quint32 *mixed = (quint32*)mixed_data;
                const quint32* back = (const quint32*)back_data;
                const quint32* front = (const quint32*)front_data;
                for (int sx = 0; sx < sw; sx++) {
                    quint32 bp = back[sx];
                    quint32 fp = front[sx];
                    mixed[sx] = qRgba ((qRed(bp)*ia + qRed(fp)*a)>>8,
                                        (qGreen(bp)*ia + qGreen(fp)*a)>>8,
                                        (qBlue(bp)*ia + qBlue(fp)*a)>>8,
                                        (qAlpha(bp)*ia + qAlpha(fp)*a)>>8);
                }
                mixed_data += bpl;
                back_data += bpl;
                front_data += bpl;
            }
        }
    default:
        break;
    }
    painter->drawImage(rect, m_tempImage);
}

void Transition::paint(QPainter *painter, const QStyleOption *option)
{
    float alpha = 1.0;
    if (m_duration > 0) {
        QTime current = QTime::currentTime();

        if (m_startTime > current)
            m_startTime = current;

        int timeDiff = m_startTime.msecsTo(current);
        alpha = timeDiff/(float)m_duration;
        if (timeDiff > m_duration) {
            m_running = false;
            alpha = 1.0;
        }
    } else {
        m_running = false;
    }
    drawBlendedImage(painter, option->rect, alpha);
}

void StyleAnimator::timerEvent(QTimerEvent *)
{
    for (int i = animations.size() - 1 ; i >= 0 ; --i) {
        if (animations[i]->widget())
            animations[i]->widget()->update();

        if (!animations[i]->widget() ||
            !animations[i]->widget()->isEnabled() ||
            !animations[i]->widget()->isVisible() ||
            animations[i]->widget()->window()->isMinimized() ||
            !animations[i]->running())
        {
            Animation *a = animations.takeAt(i);
            delete a;
        }
    }
    if (animations.size() == 0 && animationTimer.isActive())
        animationTimer.stop();
}

void StyleAnimator::stopAnimation(const QWidget *w)
{
    for (int i = animations.size() - 1 ; i >= 0 ; --i) {
        if (animations[i]->widget() == w) {
            Animation *a = animations.takeAt(i);
            delete a;
            break;
        }
    }
}

void StyleAnimator::startAnimation(Animation *t)
{
    stopAnimation(t->widget());
    animations.append(t);
    if (animations.size() > 0 && !animationTimer.isActive())
        animationTimer.start(35, this);
}



class DLL_CLASS ThemePrivate
{
public:
    ThemePrivate();

    QString fileName;
    QString name;
    QStringList preferredStyles;
    QVector<QPair<QColor, QString> > colors;
    QVector<QString> imageFiles;
    QVector<QGradientStops> gradients;
    QVector<bool> flags;
    Theme::WidgetStyle widgetStyle;
    QMap<QString, QColor> palette;
};

DLL_CLASS void setCreatorTheme(Theme *theme);


static Theme *m_creatorTheme = 0;

ThemePrivate::ThemePrivate()
    : widgetStyle(Theme::StyleDefault)
{
    const QMetaObject &m = Theme::staticMetaObject;
    colors.resize (m.enumerator(m.indexOfEnumerator("Color")).keyCount());
    imageFiles.resize (m.enumerator(m.indexOfEnumerator("ImageFile")).keyCount());
    gradients.resize (m.enumerator(m.indexOfEnumerator("Gradient")).keyCount());
    flags.resize (m.enumerator(m.indexOfEnumerator("Flag")).keyCount());
}

Theme *creatorTheme()
{
    return m_creatorTheme;
}

void setCreatorTheme(Theme *theme)
{
    if (m_creatorTheme == theme)
        return;
    delete m_creatorTheme;
    m_creatorTheme = theme;
}

Theme::Theme(const QString &name, QObject *parent)
  : QObject(parent)
  , d(new ThemePrivate)
{
    d->name = name;
}

Theme::~Theme()
{
    delete d;
}

Theme::WidgetStyle Theme::widgetStyle() const
{
    return d->widgetStyle;
}

QStringList Theme::preferredStyles() const
{
    return d->preferredStyles;
}

bool Theme::flag(Theme::Flag f) const
{
    return d->flags[f];
}

QColor Theme::color(Theme::Color role) const
{
    return d->colors[role].first;
}

QString Theme::imageFile(Theme::ImageFile imageFile, const QString &fallBack) const
{
    const QString &file = d->imageFiles.at(imageFile);
    return file.isEmpty() ? fallBack : file;
}

QGradientStops Theme::gradient(Theme::Gradient role) const
{
    return d->gradients[role];
}

QPair<QColor, QString> Theme::readNamedColor(const QString &color) const
{
    if (d->palette.contains(color))
        return qMakePair(d->palette[color], color);

    bool ok = true;
    const QRgb rgba = color.toLongLong(&ok, 16);
    if (!ok) {
        qWarning("Color '%s' is neither a named color nor a valid color", qPrintable(color));
        return qMakePair(Qt::black, QString());
    }
    return qMakePair(QColor::fromRgba(rgba), QString());
}

QString Theme::filePath() const
{
    return d->fileName;
}

QString Theme::name() const
{
    return d->name;
}

void Theme::setName(const QString &name)
{
    d->name = name;
}

QVariantHash Theme::values() const
{
    QVariantHash result;
    const QMetaObject &m = *metaObject();
    {
        const QMetaEnum e = m.enumerator(m.indexOfEnumerator("Color"));
        for (int i = 0, total = e.keyCount(); i < total; ++i) {
            const QString key = QLatin1String(e.key(i));
            const QPair<QColor, QString> &var = d->colors.at(i);
            result.insert(key, var.first);
        }
    }
    {
        const QMetaEnum e = m.enumerator(m.indexOfEnumerator("Flag"));
        for (int i = 0, total = e.keyCount(); i < total; ++i) {
            const QString key = QLatin1String(e.key(i));
            result.insert(key, flag(static_cast<Theme::Flag>(i)));
        }
    }
    {
        const QMetaEnum e = m.enumerator(m.indexOfEnumerator("WidgetStyle"));
        result.insert(QLatin1String("WidgetStyle"), QLatin1String(e.valueToKey(widgetStyle())));
    }
    return result;
}

static QColor readColor(const QString &color)
{
    bool ok = true;
    const QRgb rgba = color.toLongLong(&ok, 16);
    return QColor::fromRgba(rgba);
}

static QString writeColor(const QColor &color)
{
    return QString::number(color.rgba(), 16);
}


void Theme::writeSettings(const QString &filename) const
{
    QSettings settings(filename, QSettings::IniFormat);

    const QMetaObject &m = *metaObject();
    {
        settings.setValue(QLatin1String("ThemeName"), d->name);
        settings.setValue(QLatin1String("PreferredStyles"), d->preferredStyles);
    }
    {
        settings.beginGroup(QLatin1String("Palette"));
        for (int i = 0, total = d->colors.size(); i < total; ++i) {
            const QPair<QColor, QString> var = d->colors[i];
            if (var.second.isEmpty())
                continue;
            settings.setValue(var.second, writeColor(var.first));
        }
        settings.endGroup();
    }
    {
        settings.beginGroup(QLatin1String("Colors"));
        const QMetaEnum e = m.enumerator(m.indexOfEnumerator("Color"));
        for (int i = 0, total = e.keyCount(); i < total; ++i) {
            const QString key = QLatin1String(e.key(i));
            const QPair<QColor, QString> var = d->colors[i];
            if (!var.second.isEmpty())
                settings.setValue(key, var.second);
            else
                settings.setValue(key, writeColor(var.first));
        }
        settings.endGroup();
    }
    {
        settings.beginGroup(QLatin1String("ImageFiles"));
        const QMetaEnum e = m.enumerator(m.indexOfEnumerator("ImageFile"));
        for (int i = 0, total = e.keyCount(); i < total; ++i) {
            const QString key = QLatin1String(e.key(i));
            const QString &var = d->imageFiles.at(i);
            if (!var.isEmpty())
                settings.setValue(key, var);
        }
        settings.endGroup();
    }
    {
        settings.beginGroup(QLatin1String("Gradients"));
        const QMetaEnum e = m.enumerator(m.indexOfEnumerator("Gradient"));
        for (int i = 0, total = e.keyCount(); i < total; ++i) {
            const QString key = QLatin1String(e.key(i));
            QGradientStops stops = gradient(static_cast<Theme::Gradient>(i));
            settings.beginWriteArray(key);
            int k = 0;
            foreach (const QGradientStop stop, stops) {
                settings.setArrayIndex(k);
                settings.setValue(QLatin1String("pos"), stop.first);
                settings.setValue(QLatin1String("color"), writeColor(stop.second));
                ++k;
            }
            settings.endArray();
        }
        settings.endGroup();
    }
    {
        settings.beginGroup(QLatin1String("Flags"));
        const QMetaEnum e = m.enumerator(m.indexOfEnumerator("Flag"));
        for (int i = 0, total = e.keyCount(); i < total; ++i) {
            const QString key = QLatin1String(e.key(i));
            settings.setValue(key, flag(static_cast<Theme::Flag>(i)));
        }
        settings.endGroup();
    }

    {
        settings.beginGroup(QLatin1String("Style"));
        const QMetaEnum e = m.enumerator(m.indexOfEnumerator("WidgetStyle"));
        settings.setValue(QLatin1String("WidgetStyle"), QLatin1String(e.valueToKey(widgetStyle ())));
        settings.endGroup();
    }
}

void Theme::readSettings(QSettings &settings)
{
    d->fileName = settings.fileName();
    const QMetaObject &m = *metaObject();

    {
        d->name = settings.value(QLatin1String("ThemeName"), QLatin1String("unnamed")).toString();
        d->preferredStyles = settings.value(QLatin1String("PreferredStyles")).toStringList();
    }
    {
        settings.beginGroup(QLatin1String("Palette"));
        foreach (const QString &key, settings.allKeys()) {
            QColor c = readColor(settings.value(key).toString());
            d->palette[key] = c;
        }
        settings.endGroup();
    }
    {
        settings.beginGroup(QLatin1String("Style"));
        QMetaEnum e = m.enumerator(m.indexOfEnumerator("WidgetStyle"));
        QString val = settings.value(QLatin1String("WidgetStyle")).toString();
        d->widgetStyle = static_cast<Theme::WidgetStyle>(e.keysToValue (val.toLatin1().data()));
        settings.endGroup();
    }
    {
        settings.beginGroup(QLatin1String("Colors"));
        QMetaEnum e = m.enumerator(m.indexOfEnumerator("Color"));
        for (int i = 0, total = e.keyCount(); i < total; ++i) {
            const QString key = QLatin1String(e.key(i));

            d->colors[i] = readNamedColor(settings.value(key).toString());
        }
        settings.endGroup();
    }
    {
        settings.beginGroup(QLatin1String("ImageFiles"));
        QMetaEnum e = m.enumerator(m.indexOfEnumerator("ImageFile"));
        for (int i = 0, total = e.keyCount(); i < total; ++i) {
            const QString key = QLatin1String(e.key(i));
            d->imageFiles[i] = settings.value(key).toString();
        }
        settings.endGroup();
    }
    {
        settings.beginGroup(QLatin1String("Gradients"));
        QMetaEnum e = m.enumerator(m.indexOfEnumerator("Gradient"));
        for (int i = 0, total = e.keyCount(); i < total; ++i) {
            const QString key = QLatin1String(e.key(i));
            QGradientStops stops;
            int size = settings.beginReadArray(key);
            for (int j = 0; j < size; ++j) {
                settings.setArrayIndex(j);

                double pos = settings.value(QLatin1String("pos")).toDouble();

                QColor c = readColor(settings.value(QLatin1String("color")).toString());
                stops.append(qMakePair(pos, c));
            }
            settings.endArray();
            d->gradients[i] = stops;
        }
        settings.endGroup();
    }
    {
        settings.beginGroup(QLatin1String("Flags"));
        QMetaEnum e = m.enumerator(m.indexOfEnumerator("Flag"));
        for (int i = 0, total = e.keyCount(); i < total; ++i) {
            const QString key = QLatin1String(e.key(i));

            d->flags[i] = settings.value(key).toBool();
        }
        settings.endGroup();
    }
}

QPalette Theme::initialPalette()
{
    static QPalette palette = QApplication::palette();
    return palette;
}

QPalette Theme::palette() const
{
    QPalette pal = initialPalette();
    if (!flag(DerivePaletteFromTheme))
        return pal;



    pal.setColor(QPalette::All, QPalette::Window, color(Theme::BackgroundColorNormal));
    pal.setBrush(QPalette::All, QPalette::WindowText, color(Theme::TextColorNormal));
    pal.setColor(QPalette::All, QPalette::Base, color(Theme::BackgroundColorNormal));
    pal.setColor(QPalette::All, QPalette::AlternateBase, color(Theme::BackgroundColorAlternate));
    pal.setColor(QPalette::All, QPalette::Button, color(Theme::BackgroundColorDark));
    pal.setColor(QPalette::All, QPalette::BrightText, Qt::red);
    pal.setBrush(QPalette::All, QPalette::Text, color(Theme::TextColorNormal));
    pal.setBrush(QPalette::All, QPalette::ButtonText, color(Theme::TextColorNormal));
    pal.setBrush(QPalette::All, QPalette::ToolTipBase, color(Theme::BackgroundColorSelected));
    pal.setColor(QPalette::Highlight, color(Theme::BackgroundColorSelected));
    pal.setColor(QPalette::HighlightedText, Qt::white);
    pal.setColor(QPalette::ToolTipText, color(Theme::TextColorNormal));
    return pal;
}


static int clamp(float x)
{
    const int val = x > 255 ? 255 : static_cast<int>(x);
    return val < 0 ? 0 : val;
}


QColor StyleHelper::mergedColors(const QColor &colorA, const QColor &colorB, int factor)
{
    const int maxFactor = 100;
    QColor tmp = colorA;
    tmp.setRed((tmp.red() * factor) / maxFactor + (colorB.red() * (maxFactor - factor)) / maxFactor);
    tmp.setGreen((tmp.green() * factor) / maxFactor + (colorB.green() * (maxFactor - factor)) / maxFactor);
    tmp.setBlue((tmp.blue() * factor) / maxFactor + (colorB.blue() * (maxFactor - factor)) / maxFactor);
    return tmp;
}

qreal StyleHelper::sidebarFontSize()
{
    return 7.5;
}

QColor StyleHelper::notTooBrightHighlightColor()
{
    QColor highlightColor = qApp->palette().highlight().color();
    if (0.5 * highlightColor.saturationF() + 0.75 - highlightColor.valueF() < 0)
        highlightColor.setHsvF(highlightColor.hsvHueF(), 0.1 + highlightColor.saturationF() * 2.0, highlightColor.valueF());
    return highlightColor;
}


QPalette StyleHelper::sidebarFontPalette(const QPalette &original)
{
    QPalette palette = original;
    palette.setColor(QPalette::Active, QPalette::Text, panelTextColor());
    palette.setColor(QPalette::Active, QPalette::WindowText, panelTextColor());
    palette.setColor(QPalette::Inactive, QPalette::Text, panelTextColor().darker());
    palette.setColor(QPalette::Inactive, QPalette::WindowText, panelTextColor().darker());
    return palette;
}

QColor StyleHelper::panelTextColor(bool lightColored)
{

    if (!lightColored)
        return Qt::white;
    else
        return Qt::black;
}


QColor StyleHelper::m_baseColor;
QColor StyleHelper::m_requestedBaseColor;

QColor StyleHelper::baseColor(bool lightColored)
{
    if (!lightColored)
        return m_baseColor;
    else
        return m_baseColor.lighter(230);
}

QColor StyleHelper::highlightColor(bool lightColored)
{
    QColor result = baseColor(lightColored);
    if (!lightColored)
        result.setHsv(result.hue(),
                  clamp(result.saturation()),
                  clamp(result.value() * 1.16));
    else
        result.setHsv(result.hue(),
                  clamp(result.saturation()),
                  clamp(result.value() * 1.06));
    return result;
}

QColor StyleHelper::shadowColor(bool lightColored)
{
    QColor result = baseColor(lightColored);
    result.setHsv(result.hue(),
                  clamp(result.saturation() * 1.1),
                  clamp(result.value() * 0.70));
    return result;
}

QColor StyleHelper::borderColor(bool lightColored)
{
    QColor result = baseColor(lightColored);
    result.setHsv(result.hue(),
                  result.saturation(),
                  result.value() / 2);
    return result;
}




void StyleHelper::setBaseColor(const QColor &newcolor)
{
    m_requestedBaseColor = newcolor;

    QColor color;
    color.setHsv(newcolor.hue(),
                 newcolor.saturation() * 0.7,
                 64 + newcolor.value() / 3);

    if (color.isValid() && color != m_baseColor) {
        m_baseColor = color;
        foreach (QWidget *w, QApplication::topLevelWidgets())
            w->update();
    }
}

static void verticalGradientHelper(QPainter *p, const QRect &spanRect, const QRect &rect, bool lightColored)
{
    QColor highlight = StyleHelper::highlightColor(lightColored);
    QColor shadow = StyleHelper::shadowColor(lightColored);
    QLinearGradient grad(spanRect.topRight(), spanRect.topLeft());
    grad.setColorAt(0, highlight.lighter(117));
    grad.setColorAt(1, shadow.darker(109));
    p->fillRect(rect, grad);

    QColor light(255, 255, 255, 80);
    p->setPen(light);
    p->drawLine(rect.topRight() - QPoint(1, 0), rect.bottomRight() - QPoint(1, 0));
    QColor dark(0, 0, 0, 90);
    p->setPen(dark);
    p->drawLine(rect.topLeft(), rect.bottomLeft());
}

void StyleHelper::verticalGradient(QPainter *painter, const QRect &spanRect, const QRect &clipRect, bool lightColored)
{
    if (StyleHelper::usePixmapCache()) {
        QString key;
        QColor keyColor = baseColor(lightColored);
        key.sprintf("mh_vertical %d %d %d %d %d",
            spanRect.width(), spanRect.height(), clipRect.width(),
            clipRect.height(), keyColor.rgb());

        QPixmap pixmap;
        if (!QPixmapCache::find(key, pixmap)) {
            pixmap = QPixmap(clipRect.size());
            QPainter p(&pixmap);
            QRect rect(0, 0, clipRect.width(), clipRect.height());
            verticalGradientHelper(&p, spanRect, rect, lightColored);
            p.end();
            QPixmapCache::insert(key, pixmap);
        }

        painter->drawPixmap(clipRect.topLeft(), pixmap);
    } else {
        verticalGradientHelper(painter, spanRect, clipRect, lightColored);
    }
}

static void horizontalGradientHelper(QPainter *p, const QRect &spanRect, const
QRect &rect, bool lightColored)
{
    if (lightColored) {
        QLinearGradient shadowGradient(rect.topLeft(), rect.bottomLeft());
        shadowGradient.setColorAt(0, 0xf0f0f0);
        shadowGradient.setColorAt(1, 0xcfcfcf);
        p->fillRect(rect, shadowGradient);
        return;
    }

    QColor base = StyleHelper::baseColor(lightColored);
    QColor highlight = StyleHelper::highlightColor(lightColored);
    QColor shadow = StyleHelper::shadowColor(lightColored);
    QLinearGradient grad(rect.topLeft(), rect.bottomLeft());
    grad.setColorAt(0, highlight.lighter(120));
    if (rect.height() == StyleHelper::navigationWidgetHeight()) {
        grad.setColorAt(0.4, highlight);
        grad.setColorAt(0.401, base);
    }
    grad.setColorAt(1, shadow);
    p->fillRect(rect, grad);

    QLinearGradient shadowGradient(spanRect.topLeft(), spanRect.topRight());
        shadowGradient.setColorAt(0, QColor(0, 0, 0, 30));
    QColor lighterHighlight;
    lighterHighlight = highlight.lighter(130);
    lighterHighlight.setAlpha(100);
    shadowGradient.setColorAt(0.7, lighterHighlight);
        shadowGradient.setColorAt(1, QColor(0, 0, 0, 40));
    p->fillRect(rect, shadowGradient);
}

void StyleHelper::horizontalGradient(QPainter *painter, const QRect &spanRect, const QRect &clipRect, bool lightColored)
{
    if (StyleHelper::usePixmapCache()) {
        QString key;
        QColor keyColor = baseColor(lightColored);
        key.sprintf("mh_horizontal %d %d %d %d %d %d",
            spanRect.width(), spanRect.height(), clipRect.width(),
            clipRect.height(), keyColor.rgb(), spanRect.x());

        QPixmap pixmap;
        if (!QPixmapCache::find(key, pixmap)) {
            pixmap = QPixmap(clipRect.size());
            QPainter p(&pixmap);
            QRect rect = QRect(0, 0, clipRect.width(), clipRect.height());
            horizontalGradientHelper(&p, spanRect, rect, lightColored);
            p.end();
            QPixmapCache::insert(key, pixmap);
        }

        painter->drawPixmap(clipRect.topLeft(), pixmap);

    } else {
        horizontalGradientHelper(painter, spanRect, clipRect, lightColored);
    }
}

static void menuGradientHelper(QPainter *p, const QRect &spanRect, const QRect &rect)
{
    QLinearGradient grad(spanRect.topLeft(), spanRect.bottomLeft());
    QColor menuColor = StyleHelper::mergedColors(StyleHelper::baseColor(), QColor(244, 244, 244), 25);
    grad.setColorAt(0, menuColor.lighter(112));
    grad.setColorAt(1, menuColor);
    p->fillRect(rect, grad);
}

void StyleHelper::drawArrow(QStyle::PrimitiveElement element, QPainter *painter, const QStyleOption *option)
{
    if (option->rect.width() <= 1 || option->rect.height() <= 1)
        return;

    const qreal devicePixelRatio = painter->device()->devicePixelRatio();
    QRect r = option->rect;
    int size = qMin(r.height(), r.width());
    QPixmap pixmap;
    QString pixmapName = QString("arrow-%1-%2-%3-%4-%5-%6").arg("$qt_ia").arg(uint(option->state)).arg(element).arg(size).arg(option->palette.cacheKey()).arg(devicePixelRatio);
    if (!QPixmapCache::find(pixmapName, pixmap)) {
        const QCommonStyle* const style = qobject_cast<QCommonStyle*>(QApplication::style());
        if (!style)
            return;

        QImage image(size * devicePixelRatio, size * devicePixelRatio, QImage::Format_ARGB32_Premultiplied);
        image.fill(Qt::transparent);
        QPainter painter(&image);

        QStyleOption tweakedOption(*option);
        tweakedOption.state = QStyle::State_Enabled;

        if (!(option->state & QStyle::State_Enabled)) {
            tweakedOption.palette.setColor(QPalette::ButtonText, option->palette.mid().color());
            tweakedOption.rect = image.rect();
            style->QCommonStyle::drawPrimitive(element, &tweakedOption, &painter);
        } else {
            tweakedOption.palette.setColor(QPalette::ButtonText, Qt::black);
            painter.setOpacity(0.2);
            tweakedOption.rect = image.rect().adjusted(0, devicePixelRatio, 0, devicePixelRatio);
            style->QCommonStyle::drawPrimitive(element, &tweakedOption, &painter);

            tweakedOption.palette.setColor(QPalette::ButtonText, QColor(220, 220, 220));
            painter.setOpacity(1);
            tweakedOption.rect = image.rect();
            style->QCommonStyle::drawPrimitive(element, &tweakedOption, &painter);
        }
        painter.end();
        pixmap = QPixmap::fromImage(image);
        pixmap.setDevicePixelRatio(devicePixelRatio);
        QPixmapCache::insert(pixmapName, pixmap);
    }
    int xOffset = r.x() + (r.width() - size)/2;
    int yOffset = r.y() + (r.height() - size)/2;
    painter->drawPixmap(xOffset, yOffset, pixmap);
}

void StyleHelper::menuGradient(QPainter *painter, const QRect &spanRect, const QRect &clipRect)
{
    if (StyleHelper::usePixmapCache()) {
        QString key;
        key.sprintf("mh_menu %d %d %d %d %d",
            spanRect.width(), spanRect.height(), clipRect.width(),
            clipRect.height(), StyleHelper::baseColor().rgb());

        QPixmap pixmap;
        if (!QPixmapCache::find(key, pixmap)) {
            pixmap = QPixmap(clipRect.size());
            QPainter p(&pixmap);
            QRect rect = QRect(0, 0, clipRect.width(), clipRect.height());
            menuGradientHelper(&p, spanRect, rect);
            p.end();
            QPixmapCache::insert(key, pixmap);
        }

        painter->drawPixmap(clipRect.topLeft(), pixmap);
    } else {
        menuGradientHelper(painter, spanRect, clipRect);
    }
}


void StyleHelper::drawIconWithShadow(const QIcon &icon, const QRect &rect,
                                     QPainter *p, QIcon::Mode iconMode, int dipRadius, const QColor &color, const QPoint &dipOffset)
{
    QPixmap cache;
    QString pixmapName = QString::fromLatin1("icon %0 %1 %2").arg(icon.cacheKey()).arg(iconMode).arg(rect.height());

    if (!QPixmapCache::find(pixmapName, cache)) {





        QPixmap px = icon.pixmap(rect.size());
        int devicePixelRatio = qCeil(px.devicePixelRatio());
        int radius = dipRadius * devicePixelRatio;
        QPoint offset = dipOffset * devicePixelRatio;
        cache = QPixmap(px.size() + QSize(radius * 2, radius * 2));
        cache.fill(Qt::transparent);

        QPainter cachePainter(&cache);
        if (iconMode == QIcon::Disabled) {
            QImage im = px.toImage().convertToFormat(QImage::Format_ARGB32);
            for (int y=0; y<im.height(); ++y) {
                QRgb *scanLine = (QRgb*)im.scanLine(y);
                for (int x=0; x<im.width(); ++x) {
                    QRgb pixel = *scanLine;
                    char intensity = qGray(pixel);
                    *scanLine = qRgba(intensity, intensity, intensity, qAlpha(pixel));
                    ++scanLine;
                }
            }
            px = QPixmap::fromImage(im);
        }


        QImage tmp(px.size() + QSize(radius * 2, radius * 2 + 1), QImage::Format_ARGB32_Premultiplied);
        tmp.fill(Qt::transparent);

        QPainter tmpPainter(&tmp);
        tmpPainter.setCompositionMode(QPainter::CompositionMode_Source);
        tmpPainter.drawPixmap(QRect(radius, radius, px.width(), px.height()), px);
        tmpPainter.end();


        QImage blurred(tmp.size(), QImage::Format_ARGB32_Premultiplied);
        blurred.fill(Qt::transparent);
        QPainter blurPainter(&blurred);
        qt_blurImage(&blurPainter, tmp, radius, false, true);
        blurPainter.end();

        tmp = blurred;


        tmpPainter.begin(&tmp);
        tmpPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
        tmpPainter.fillRect(tmp.rect(), color);
        tmpPainter.end();

        tmpPainter.begin(&tmp);
        tmpPainter.setCompositionMode(QPainter::CompositionMode_SourceIn);
        tmpPainter.fillRect(tmp.rect(), color);
        tmpPainter.end();


        cachePainter.drawImage(QRect(0, 0, cache.rect().width(), cache.rect().height()), tmp);


        cachePainter.drawPixmap(QRect(QPoint(radius, radius) + offset, QSize(px.width(), px.height())), px);
        cache.setDevicePixelRatio(devicePixelRatio);
        QPixmapCache::insert(pixmapName, cache);
    }

    QRect targetRect = cache.rect();
    targetRect.setSize(targetRect.size() / cache.devicePixelRatio());
    targetRect.moveCenter(rect.center() - dipOffset);
    p->drawPixmap(targetRect, cache);
}



void StyleHelper::drawCornerImage(const QImage &img, QPainter *painter, const QRect &rect,
                                  int left, int top, int right, int bottom)
{

    const qreal imagePixelRatio = img.devicePixelRatio();
    const qreal leftDIP = left * imagePixelRatio;
    const qreal topDIP = top * imagePixelRatio;
    const qreal rightDIP = right * imagePixelRatio;
    const qreal bottomDIP = bottom * imagePixelRatio;

    const QSize size = img.size();
    if (top > 0) {
        painter->drawImage(QRectF(rect.left() + left, rect.top(), rect.width() -right - left, top), img,
                           QRectF(leftDIP, 0, size.width() - rightDIP - leftDIP, topDIP));
        if (left > 0)
            painter->drawImage(QRectF(rect.left(), rect.top(), left, top), img,
                               QRectF(0, 0, leftDIP, topDIP));
        if (right > 0)
            painter->drawImage(QRectF(rect.left() + rect.width() - right, rect.top(), right, top), img,
                               QRectF(size.width() - rightDIP, 0, rightDIP, topDIP));
    }

    if (left > 0)
        painter->drawImage(QRectF(rect.left(), rect.top()+top, left, rect.height() - top - bottom), img,
                           QRectF(0, topDIP, leftDIP, size.height() - bottomDIP - topDIP));

    painter->drawImage(QRectF(rect.left() + left, rect.top()+top, rect.width() -right - left,
                              rect.height() - bottom - top), img,
                       QRectF(leftDIP, topDIP, size.width() - rightDIP - leftDIP,
                              size.height() - bottomDIP - topDIP));
    if (right > 0)
        painter->drawImage(QRectF(rect.left() +rect.width() - right, rect.top()+top, right, rect.height() - top - bottom), img,
                           QRectF(size.width() - rightDIP, topDIP, rightDIP, size.height() - bottomDIP - topDIP));
    if (bottom > 0) {
        painter->drawImage(QRectF(rect.left() +left, rect.top() + rect.height() - bottom,
                                  rect.width() - right - left, bottom), img,
                           QRectF(leftDIP, size.height() - bottomDIP,
                                  size.width() - rightDIP - leftDIP, bottomDIP));
        if (left > 0)
            painter->drawImage(QRectF(rect.left(), rect.top() + rect.height() - bottom, left, bottom), img,
                               QRectF(0, size.height() - bottomDIP, leftDIP, bottomDIP));
        if (right > 0)
            painter->drawImage(QRectF(rect.left() + rect.width() - right, rect.top() + rect.height() - bottom, right, bottom), img,
                               QRectF(size.width() - rightDIP, size.height() - bottomDIP, rightDIP, bottomDIP));
    }
}


void StyleHelper::tintImage(QImage &img, const QColor &tintColor)
{
    QPainter p(&img);
    p.setCompositionMode(QPainter::CompositionMode_Screen);

    for (int x = 0; x < img.width(); ++x) {
        for (int y = 0; y < img.height(); ++y) {
            QRgb rgbColor = img.pixel(x, y);
            int alpha = qAlpha(rgbColor);
            QColor c = QColor(rgbColor);

            if (alpha > 0) {
                c.toHsl();
                qreal l = c.lightnessF();
                QColor newColor = QColor::fromHslF(tintColor.hslHueF(), tintColor.hslSaturationF(), l);
                newColor.setAlpha(alpha);
                img.setPixel(x, y, newColor.rgba());
            }
        }
    }
}

QLinearGradient StyleHelper::statusBarGradient(const QRect &statusBarRect)
{
    QLinearGradient grad(statusBarRect.topLeft(), QPoint(statusBarRect.center().x(), statusBarRect.bottom()));
    QColor startColor = shadowColor().darker(164);
    QColor endColor = baseColor().darker(130);
    grad.setColorAt(0, startColor);
    grad.setColorAt(1, endColor);
    return grad;
}

QString StyleHelper::dpiSpecificImageFile(const QString &fileName)
{

    if (qApp->devicePixelRatio() > 1.0) {
        const QFileInfo fi(fileName);
        const QString at2xfileName = fi.path() + QLatin1Char('/')
                + fi.completeBaseName() + QStringLiteral("@2x.") + fi.suffix();
        if (QFile::exists(at2xfileName))
            return at2xfileName;
    }
    return fileName;
}




const QStyle::State State_Animating = QStyle::State(0x00000040);



bool styleEnabled(const QWidget *widget)
{
    const QWidget *p = widget;
    while (p) {
        if (p->property("_q_custom_style_disabled").toBool())
            return false;
        p = p->parentWidget();
    }
    return true;
}


bool panelWidget(const QWidget *widget)
{
    if (!widget)
        return false;


    if ((widget->window()->windowFlags() & Qt::WindowType_Mask) == Qt::Dialog)
        return false;




    if (qobject_cast<const QTabBar *>(widget))
        return styleEnabled(widget);

    const QWidget *p = widget;
    while (p) {
        if (qobject_cast<const QToolBar *>(p) ||
            qobject_cast<const QStatusBar *>(p) ||
            qobject_cast<const QMenuBar *>(p) ||
            p->property("panelwidget").toBool())
            return styleEnabled(widget);
        p = p->parentWidget();
    }
    return false;
}


bool lightColored(const QWidget *widget)
{
    if (!widget)
        return false;


    if ((widget->window()->windowFlags() & Qt::WindowType_Mask) == Qt::Dialog)
        return false;

    const QWidget *p = widget;
    while (p) {
        if (p->property("lightColored").toBool())
            return true;
        p = p->parentWidget();
    }
    return false;
}

class ManhattanStylePrivate
{
public:
    explicit ManhattanStylePrivate();
    void init();

public:
    const QImage lineeditImage;
    const QImage lineeditImage_disabled;
    const QPixmap extButtonPixmap;
    const QPixmap closeButtonPixmap;
    StyleAnimator animator;
};

ManhattanStylePrivate::ManhattanStylePrivate() :
    lineeditImage(StyleHelper::dpiSpecificImageFile(QStringLiteral(":/core/images/inputfield.png"))),
    lineeditImage_disabled(StyleHelper::dpiSpecificImageFile(QStringLiteral(":/core/images/inputfield_disabled.png"))),
    extButtonPixmap(QLatin1String(":/core/images/extension.png")),
    closeButtonPixmap(QLatin1String(":/core/images/extension.png"))
{
}

ManhattanStyle::ManhattanStyle(const QString &baseStyleName)
    : QProxyStyle(QStyleFactory::create(baseStyleName)),
    d(new ManhattanStylePrivate())
{
    m_width = 30;
    QString themeName="default";
    QString themeURI = QCoreApplication::applicationDirPath()+"/themes/"+themeName+".creatortheme";

    QSettings themeSettings(themeURI, QSettings::IniFormat);
    Theme *theme = new Theme(themeName, qApp);
    theme->readSettings(themeSettings);
    if (theme->flag(Theme::ApplyThemePaletteGlobally))
        QApplication::setPalette(theme->palette());
    setCreatorTheme(theme);

    StyleHelper::setBaseColor( QColor(StyleHelper::DEFAULT_BASE_COLOR));
}

ManhattanStyle::~ManhattanStyle()
{
    delete d;
    d = 0;
}

QPixmap ManhattanStyle::generatedIconPixmap(QIcon::Mode iconMode, const QPixmap &pixmap, const QStyleOption *opt) const
{
    return QProxyStyle::generatedIconPixmap(iconMode, pixmap, opt);
}

QSize ManhattanStyle::sizeFromContents(ContentsType type, const QStyleOption *option,
                                       const QSize &size, const QWidget *widget) const
{
    QSize newSize = QProxyStyle::sizeFromContents(type, option, size, widget);

    if (type == CT_Splitter && widget && widget->property("minisplitter").toBool())
        return QSize(1, 1);
    else if (type == CT_ComboBox && panelWidget(widget))
        newSize += QSize(14, 0);
    else
    {
        newSize=sizeFromContentsTab(type, option, size, widget);
    }
    return newSize;
}

QRect ManhattanStyle::subElementRect(SubElement element, const QStyleOption *option, const QWidget *widget) const
{
    return QProxyStyle::subElementRect(element, option, widget);
}

QRect ManhattanStyle::subControlRect(ComplexControl control, const QStyleOptionComplex *option,
                                     SubControl subControl, const QWidget *widget) const
{
    return QProxyStyle::subControlRect(control, option, subControl, widget);
}

QStyle::SubControl ManhattanStyle::hitTestComplexControl(ComplexControl control, const QStyleOptionComplex *option,
                                                         const QPoint &pos, const QWidget *widget) const
{
    return QProxyStyle::hitTestComplexControl(control, option, pos, widget);
}

int ManhattanStyle::pixelMetric(PixelMetric metric, const QStyleOption *option, const QWidget *widget) const
{
    int retval = 0;
    retval = QProxyStyle::pixelMetric(metric, option, widget);
    switch (metric) {
    case PM_SplitterWidth:
        if (widget && widget->property("minisplitter").toBool())
            retval = 1;
        break;
    case PM_ToolBarIconSize:
        if (panelWidget(widget))
            retval = 16;
        break;
    case PM_DockWidgetHandleExtent:
    case PM_DockWidgetSeparatorExtent:
        return 1;
    case PM_MenuPanelWidth:
    case PM_MenuBarHMargin:
    case PM_MenuBarVMargin:
    case PM_ToolBarFrameWidth:
        if (panelWidget(widget))
            retval = 1;
        break;
    case PM_ButtonShiftVertical:
    case PM_ButtonShiftHorizontal:
    case PM_MenuBarPanelWidth:
    case PM_ToolBarItemMargin:
    case PM_ToolBarItemSpacing:
        if (panelWidget(widget))
            retval = 0;
        break;
    case PM_DefaultFrameWidth:
        if (qobject_cast<const QLineEdit*>(widget) && panelWidget(widget))
            return 1;
        break;
    default:
        break;
    }
    return retval;
}

QPalette ManhattanStyle::standardPalette() const
{
    return QProxyStyle::standardPalette();
}

void ManhattanStyle::polish(QApplication *app)
{
    return QProxyStyle::polish(app);
}

void ManhattanStyle::unpolish(QApplication *app)
{
    return QProxyStyle::unpolish(app);
}

QPalette panelPalette(const QPalette &oldPalette, bool lightColored = false)
{
    QColor color = creatorTheme()->color(lightColored ? Theme::PanelTextColorDark
                                                      : Theme::PanelTextColorLight);
    QPalette pal = oldPalette;
    pal.setBrush(QPalette::All, QPalette::WindowText, color);
    pal.setBrush(QPalette::All, QPalette::ButtonText, color);
    pal.setBrush(QPalette::All, QPalette::Foreground, color);
    color.setAlpha(100);
    pal.setBrush(QPalette::Disabled, QPalette::WindowText, color);
    pal.setBrush(QPalette::Disabled, QPalette::ButtonText, color);
    pal.setBrush(QPalette::Disabled, QPalette::Foreground, color);
    return pal;
}

void ManhattanStyle::polish(QWidget *widget)
{
    QProxyStyle::polish(widget);


    if (baseStyle()->inherits("OxygenStyle") || baseStyle()->inherits("Oxygen::Style")) {
        if (qobject_cast<QToolBar*>(widget) || qobject_cast<QDockWidget*>(widget)) {
            widget->removeEventFilter(baseStyle());
            widget->setContentsMargins(0, 0, 0, 0);
        }
    }
    if (panelWidget(widget)) {


        if (qobject_cast<QDockWidget*>(widget))
            widget->setContentsMargins(0, 0, 0, 0);

        widget->setAttribute(Qt::WA_LayoutUsesWidgetRect, true);
        if (qobject_cast<QToolButton*>(widget)) {
            widget->setAttribute(Qt::WA_Hover);
            widget->setMaximumHeight(StyleHelper::navigationWidgetHeight() - 2);
        } else if (qobject_cast<QLineEdit*>(widget)) {
            widget->setAttribute(Qt::WA_Hover);
            widget->setMaximumHeight(StyleHelper::navigationWidgetHeight() - 2);
        } else if (qobject_cast<QLabel*>(widget)) {
            widget->setPalette(panelPalette(widget->palette(), lightColored(widget)));
        } else if (widget->property("panelwidget_singlerow").toBool()) {
            widget->setFixedHeight(StyleHelper::navigationWidgetHeight());
        } else if (qobject_cast<QStatusBar*>(widget)) {
            widget->setFixedHeight(StyleHelper::navigationWidgetHeight() + 2);
        } else if (qobject_cast<QComboBox*>(widget)) {
           widget->setMaximumHeight(StyleHelper::navigationWidgetHeight() - 2);
            widget->setAttribute(Qt::WA_Hover);
        }
    }
}

void ManhattanStyle::unpolish(QWidget *widget)
{
    QProxyStyle::unpolish(widget);
    if (panelWidget(widget)) {
        widget->setAttribute(Qt::WA_LayoutUsesWidgetRect, false);
        if (qobject_cast<QTabBar*>(widget))
            widget->setAttribute(Qt::WA_Hover, false);
        else if (qobject_cast<QToolBar*>(widget))
            widget->setAttribute(Qt::WA_Hover, false);
        else if (qobject_cast<QComboBox*>(widget))
            widget->setAttribute(Qt::WA_Hover, false);
    }
}

void ManhattanStyle::polish(QPalette &pal)
{
    QProxyStyle::polish(pal);
}

QIcon ManhattanStyle::standardIconImplementation(StandardPixmap standardIcon, const QStyleOption *option, const QWidget *widget) const
{
    QIcon icon;
    switch (standardIcon) {
    case QStyle::SP_TitleBarCloseButton:
    case QStyle::SP_ToolBarHorizontalExtensionButton:
        return QIcon(standardPixmap(standardIcon, option, widget));
    default:
        icon = baseStyle()->standardIcon(standardIcon, option, widget);
    }
    return icon;
}

QPixmap ManhattanStyle::standardPixmap(StandardPixmap standardPixmap, const QStyleOption *opt,
                                       const QWidget *widget) const
{
    if (widget && !panelWidget(widget))
        return QProxyStyle::standardPixmap(standardPixmap, opt, widget);

    QPixmap pixmap;
    switch (standardPixmap) {
    case QStyle::SP_ToolBarHorizontalExtensionButton:
        pixmap = d->extButtonPixmap;
        break;
    case QStyle::SP_TitleBarCloseButton:
        pixmap = d->closeButtonPixmap;
        break;
    default:
        pixmap = QProxyStyle::standardPixmap(standardPixmap, opt, widget);
        break;
    }
    return pixmap;
}

int ManhattanStyle::styleHint(StyleHint hint, const QStyleOption *option, const QWidget *widget,
                              QStyleHintReturn *returnData) const
{
    int ret = QProxyStyle::styleHint(hint, option, widget, returnData);
    switch (hint) {

    case QStyle::SH_ItemView_PaintAlternatingRowColorsForEmptyArea:
        if (widget && widget->property("AlternateEmpty").toBool())
            ret = true;
        break;
    case QStyle::SH_EtchDisabledText:
        if (panelWidget(widget))
            ret = false;
        break;
    case QStyle::SH_ItemView_ArrowKeysNavigateIntoChildren:
        ret = true;
        break;
    case QStyle::SH_ItemView_ActivateItemOnSingleClick:

        if (widget) {
            QVariant activationMode = widget->property("ActivationMode");
            if (activationMode.isValid())
                ret = activationMode.toBool();
        }
    default:
        break;
    }
    return ret;
}

void ManhattanStyle::drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                                   QPainter *painter, const QWidget *widget) const
{
    if (!panelWidget(widget))
        return QProxyStyle::drawPrimitive(element, option, painter, widget);

    bool animating = (option->state & State_Animating);
    int state = option->state;
    QRect rect = option->rect;
    QRect oldRect;
    QRect newRect;
    if (widget && (element == PE_PanelButtonTool) && !animating) {
        QWidget *w = const_cast<QWidget *> (widget);
        int oldState = w->property("_q_stylestate").toInt();
        oldRect = w->property("_q_stylerect").toRect();
        newRect = w->rect();
        w->setProperty("_q_stylestate", (int)option->state);
        w->setProperty("_q_stylerect", w->rect());
    }

    switch (element) {
    case PE_IndicatorDockWidgetResizeHandle:
        painter->fillRect(option->rect, creatorTheme()->color(Theme::DockWidgetResizeHandleColor));
        break;
    case PE_FrameDockWidget:
        QCommonStyle::drawPrimitive(element, option, painter, widget);
        break;
    case PE_PanelLineEdit:
        {
            painter->save();


            QRect filledRect = option->rect.adjusted(1, 1, -1, -1);
            painter->setBrushOrigin(filledRect.topLeft());
            painter->fillRect(filledRect, option->palette.base());

            if (option->state & State_Enabled)
                StyleHelper::drawCornerImage(d->lineeditImage, painter, option->rect, 5, 5, 5, 5);
            else
                StyleHelper::drawCornerImage(d->lineeditImage_disabled, painter, option->rect, 5, 5, 5, 5);

            if (option->state & State_HasFocus || option->state & State_MouseOver) {
                QColor hover = StyleHelper::baseColor();
                if (state & State_HasFocus)
                    hover.setAlpha(100);
                else
                    hover.setAlpha(50);

                painter->setPen(QPen(hover, 1));
                painter->drawRect(QRectF(option->rect).adjusted(1.5, 1.5, -1.5, -1.5));
            }
            painter->restore();
        }
        break;

    case PE_FrameStatusBarItem:
        break;

    case PE_PanelButtonTool: {





            {
                bool pressed = option->state & State_Sunken || option->state & State_On;
                QColor shadow(0, 0, 0, 30);
                painter->setPen(shadow);
                if (pressed) {
                    QColor shade(0, 0, 0, 40);
                    painter->fillRect(rect, shade);
                    painter->drawLine(rect.topLeft() + QPoint(1, 0), rect.topRight() - QPoint(1, 0));
                    painter->drawLine(rect.topLeft(), rect.bottomLeft());
                    painter->drawLine(rect.topRight(), rect.bottomRight());

                    QColor highlight(255, 255, 255, 30);
                    painter->setPen(highlight);
                } else if (option->state & State_Enabled && option->state & State_MouseOver) {
                    painter->fillRect(rect, creatorTheme()->color(Theme::PanelButtonToolBackgroundColorHover));
                } else if (widget && widget->property("highlightWidget").toBool()) {
                    QColor shade(0, 0, 0, 128);
                    painter->fillRect(rect, shade);
                }
                if (option->state & State_HasFocus && (option->state & State_KeyboardFocusChange)) {
                    QColor highlight = option->palette.highlight().color();
                    highlight.setAlphaF(0.4);
                    painter->setPen(QPen(highlight.lighter(), 1));
                    highlight.setAlphaF(0.3);
                    painter->setBrush(highlight);
                    painter->setRenderHint(QPainter::Antialiasing);
                    const QRectF rect = option->rect;
                    painter->drawRoundedRect(rect.adjusted(2.5, 2.5, -2.5, -2.5), 2, 2);
                }
           }
        }
        break;

    case PE_PanelStatusBar:
        {
            if (creatorTheme()->widgetStyle() == Theme::StyleDefault) {
                painter->save();
                QLinearGradient grad = StyleHelper::statusBarGradient(rect);
                painter->fillRect(rect, grad);
                painter->setPen(QColor(255, 255, 255, 60));
                painter->drawLine(rect.topLeft() + QPoint(0,1),
                                  rect.topRight()+ QPoint(0,1));
                painter->setPen(StyleHelper::borderColor().darker(110));
                painter->drawLine(rect.topLeft(), rect.topRight());
                painter->restore();
            } else {
                painter->fillRect(rect, creatorTheme()->color(Theme::PanelStatusBarBackgroundColor));
            }
        }
        break;

    case PE_IndicatorToolBarSeparator:
        {
            QColor separatorColor = StyleHelper::borderColor();
            separatorColor.setAlpha(100);
            painter->setPen(separatorColor);
            const int margin = 6;
            if (option->state & State_Horizontal) {
                const int offset = rect.width()/2;
                painter->drawLine(rect.bottomLeft().x() + offset,
                            rect.bottomLeft().y() - margin,
                            rect.topLeft().x() + offset,
                            rect.topLeft().y() + margin);
            } else {
                const int offset = rect.height()/2;
                painter->setPen(QPen(option->palette.background().color().darker(110)));
                painter->drawLine(rect.topLeft().x() + margin ,
                            rect.topLeft().y() + offset,
                            rect.topRight().x() - margin,
                            rect.topRight().y() + offset);
            }
        }
        break;

    case PE_IndicatorToolBarHandle:
        {
            bool horizontal = option->state & State_Horizontal;
            painter->save();
            QPainterPath path;
            int x = option->rect.x() + (horizontal ? 2 : 6);
            int y = option->rect.y() + (horizontal ? 6 : 2);
            static const int RectHeight = 2;
            if (horizontal) {
                while (y < option->rect.height() - RectHeight - 6) {
                    path.moveTo(x, y);
                    path.addRect(x, y, RectHeight, RectHeight);
                    y += 6;
                }
            } else {
                while (x < option->rect.width() - RectHeight - 6) {
                    path.moveTo(x, y);
                    path.addRect(x, y, RectHeight, RectHeight);
                    x += 6;
                }
            }

            painter->setPen(Qt::NoPen);
            QColor dark = StyleHelper::borderColor();
            dark.setAlphaF(0.4);

            QColor light = StyleHelper::baseColor();
            light.setAlphaF(0.4);

            painter->fillPath(path, light);
            painter->save();
            painter->translate(1, 1);
            painter->fillPath(path, dark);
            painter->restore();
            painter->translate(3, 3);
            painter->fillPath(path, light);
            painter->translate(1, 1);
            painter->fillPath(path, dark);
            painter->restore();
        }
        break;
    case PE_IndicatorArrowUp:
    case PE_IndicatorArrowDown:
    case PE_IndicatorArrowRight:
    case PE_IndicatorArrowLeft:
        {
            StyleHelper::drawArrow(element, painter, option);
        }
        break;

    default:
        QProxyStyle::drawPrimitive(element, option, painter, widget);
        break;
    }
}

void ManhattanStyle::drawControl(ControlElement element, const QStyleOption *option,
                                 QPainter *painter, const QWidget *widget) const
{
    if (!panelWidget(widget))
        return QProxyStyle::drawControl(element, option, painter, widget);

    switch (element) {
    case CE_Splitter:
        painter->fillRect(option->rect, StyleHelper::borderColor());
        break;

    case CE_TabBarTabLabel:
    case CE_TabBarTabShape:
        paintTabs(element, option, painter, widget);
        /*
        if (const QStyleOptionTabV3 *tab = qstyleoption_cast<const QStyleOptionTabV3 *>(option)) {
            QStyleOptionTabV3 adjustedTab = *tab;
            if (tab->cornerWidgets == QStyleOptionTab::NoCornerWidgets && (
                    tab->position == QStyleOptionTab::Beginning ||
                    tab->position == QStyleOptionTab::OnlyOneTab))
            {
                if (option->direction == Qt::LeftToRight)
                    adjustedTab.rect = adjustedTab.rect.adjusted(-1, 0, 0, 0);
                else
                    adjustedTab.rect = adjustedTab.rect.adjusted(0, 0, 1 ,0);
            }
            QProxyStyle::drawControl(element, &adjustedTab, painter, widget);
            return;
        }*/
        break;

    case CE_MenuBarItem:
        painter->save();
        if (const QStyleOptionMenuItem *mbi = qstyleoption_cast<const QStyleOptionMenuItem *>(option)) {
            QColor highlightOutline = StyleHelper::borderColor().lighter(120);
            const bool act = mbi->state & (State_Sunken | State_Selected);
            const bool dis = !(mbi->state & State_Enabled);

            if (creatorTheme()->widgetStyle() == Theme::StyleFlat)
                painter->fillRect(option->rect, creatorTheme()->color(Theme::MenuBarItemBackgroundColor));
            else
                StyleHelper::menuGradient(painter, option->rect, option->rect);

            QStyleOptionMenuItem item = *mbi;
            item.rect = mbi->rect;
            QPalette pal = mbi->palette;
            pal.setBrush(QPalette::ButtonText, dis
                ? creatorTheme()->color(Theme::MenuBarItemTextColorDisabled)
                : creatorTheme()->color(Theme::MenuBarItemTextColorNormal));
            item.palette = pal;
            QCommonStyle::drawControl(element, &item, painter, widget);

            if (act) {

                QColor baseColor = StyleHelper::baseColor();
                QLinearGradient grad(option->rect.topLeft(), option->rect.bottomLeft());
                grad.setColorAt(0, baseColor.lighter(120));
                grad.setColorAt(1, baseColor.lighter(130));
                painter->fillRect(option->rect.adjusted(1, 1, -1, 0), grad);


                painter->setPen(QPen(highlightOutline, 0));
                const QRect r = option->rect;
                painter->drawLine(QPoint(r.left(), r.top() + 1), QPoint(r.left(), r.bottom()));
                painter->drawLine(QPoint(r.right(), r.top() + 1), QPoint(r.right(), r.bottom()));
                painter->drawLine(QPoint(r.left() + 1, r.top()), QPoint(r.right() - 1, r.top()));
                highlightOutline.setAlpha(60);
                painter->setPen(QPen(highlightOutline, 0));
                painter->drawPoint(r.topLeft());
                painter->drawPoint(r.topRight());

                QPalette pal = mbi->palette;
                uint alignment = Qt::AlignCenter | Qt::TextShowMnemonic | Qt::TextDontClip | Qt::TextSingleLine;
                if (!styleHint(SH_UnderlineShortcut, mbi, widget))
                    alignment |= Qt::TextHideMnemonic;
                pal.setBrush(QPalette::Text, dis ? Qt::gray : QColor(0, 0, 0, 60));
                drawItemText(painter, item.rect.translated(0, 1), alignment, pal, mbi->state & State_Enabled, mbi->text, QPalette::Text);
                pal.setBrush(QPalette::Text, dis ? Qt::gray : Qt::white);
                drawItemText(painter, item.rect, alignment, pal, mbi->state & State_Enabled, mbi->text, QPalette::Text);
            }
        }
        painter->restore();
        break;

    case CE_ComboBoxLabel:
        if (const QStyleOptionComboBox *cb = qstyleoption_cast<const QStyleOptionComboBox *>(option)) {
            if (panelWidget(widget)) {
                painter->save();
                QRect editRect = subControlRect(CC_ComboBox, cb, SC_ComboBoxEditField, widget);
                QPalette customPal = cb->palette;
                bool drawIcon = !(widget && widget->property("hideicon").toBool());

                if (!cb->currentIcon.isNull() && drawIcon) {
                    QIcon::Mode mode = cb->state & State_Enabled ? QIcon::Normal
                                                                 : QIcon::Disabled;
                    QPixmap pixmap = cb->currentIcon.pixmap(cb->iconSize, mode);
                    QRect iconRect(editRect);
                    iconRect.setWidth(cb->iconSize.width() + 4);
                    iconRect = alignedRect(cb->direction,
                                           Qt::AlignLeft | Qt::AlignVCenter,
                                           iconRect.size(), editRect);
                    if (cb->editable)
                        painter->fillRect(iconRect, customPal.brush(QPalette::Base));
                    drawItemPixmap(painter, iconRect, Qt::AlignCenter, pixmap);

                    if (cb->direction == Qt::RightToLeft)
                        editRect.translate(-4 - cb->iconSize.width(), 0);
                    else
                        editRect.translate(cb->iconSize.width() + 4, 0);


                    editRect.adjust(0, 0, -13, 0);
                }

                QLatin1Char asterisk('*');
                int elideWidth = editRect.width();

                bool notElideAsterisk = widget && widget->property("notelideasterisk").toBool()
                                        && cb->currentText.endsWith(asterisk)
                                        && option->fontMetrics.width(cb->currentText) > elideWidth;

                QString text;
                if (notElideAsterisk) {
                    elideWidth -= option->fontMetrics.width(asterisk);
                    text = asterisk;
                }
                text.prepend(option->fontMetrics.elidedText(cb->currentText, Qt::ElideRight, elideWidth));

                if (creatorTheme()->flag(Theme::ComboBoxDrawTextShadow)
                    && (option->state & State_Enabled))
                {
                    painter->setPen(QColor(0, 0, 0, 70));
                    painter->drawText(editRect.adjusted(1, 0, -1, 0), Qt::AlignLeft | Qt::AlignVCenter, text);
                }
                if (!(option->state & State_Enabled))
                    painter->setOpacity(0.8);
                painter->setPen(creatorTheme()->color(Theme::ComboBoxTextColor));
                painter->drawText(editRect.adjusted(1, 0, -1, 0), Qt::AlignLeft | Qt::AlignVCenter, text);

                painter->restore();
            } else {
                QProxyStyle::drawControl(element, option, painter, widget);
            }
        }
        break;

    case CE_SizeGrip: {
            painter->save();
            QColor dark = Qt::white;
            dark.setAlphaF(0.1);
            int x, y, w, h;
            option->rect.getRect(&x, &y, &w, &h);
            int sw = qMin(h, w);
            if (h > w)
                painter->translate(0, h - w);
            else
                painter->translate(w - h, 0);
            int sx = x;
            int sy = y;
            int s = 4;
            painter->setPen(dark);
            if (option->direction == Qt::RightToLeft) {
                sx = x + sw;
                for (int i = 0; i < 4; ++i) {
                    painter->drawLine(x, sy, sx, sw);
                    sx -= s;
                    sy += s;
                }
            } else {
                for (int i = 0; i < 4; ++i) {
                    painter->drawLine(sx, sw, sw, sy);
                    sx += s;
                    sy += s;
                }
            }
            painter->restore();
        }
        break;

    case CE_MenuBarEmptyArea: {
            if (creatorTheme()->widgetStyle() == Theme::StyleDefault) {
                StyleHelper::menuGradient(painter, option->rect, option->rect);
                painter->save();
                painter->setPen(StyleHelper::borderColor());
                painter->drawLine(option->rect.bottomLeft() + QPointF(0.5, 0.5),
                                  option->rect.bottomRight() + QPointF(0.5, 0.5));
                painter->restore();
            } else {
                painter->fillRect(option->rect, creatorTheme()->color(Theme::MenuBarEmptyAreaBackgroundColor));
            }
        }
        break;

    case CE_ToolBar:
        {
            QRect rect = option->rect;
            bool horizontal = option->state & State_Horizontal;


            QRect gradientSpan;
            if (widget) {
                QPoint offset = widget->window()->mapToGlobal(option->rect.topLeft()) -
                                widget->mapToGlobal(option->rect.topLeft());
                gradientSpan = QRect(offset, widget->window()->size());
            }

            bool drawLightColored = lightColored(widget);
            if (horizontal)
            {

                if (creatorTheme()->widgetStyle() == Theme::StyleFlat)
                    painter->fillRect (rect, creatorTheme()->color(Theme::ToolBarBackgroundColor));
                else
                    StyleHelper::horizontalGradient(painter, gradientSpan, rect, drawLightColored);
            } else {
                if (creatorTheme()->widgetStyle() == Theme::StyleFlat)
                    painter->fillRect (rect, creatorTheme()->color(Theme::ToolBarBackgroundColor));
                else
                    StyleHelper::verticalGradient(painter, gradientSpan, rect, drawLightColored);
            }

            if (!drawLightColored) {
                painter->setPen(StyleHelper::borderColor());
            }
            else
                painter->setPen(QColor(0x888888));

            if (horizontal) {



                QColor lighter(StyleHelper::sidebarHighlight());
                if (drawLightColored)
                    lighter = QColor(255, 255, 255, 180);
                if (widget && widget->property("topBorder").toBool()) {
                    painter->drawLine(rect.topLeft(), rect.topRight());
                    painter->setPen(lighter);
                    painter->drawLine(rect.topLeft() + QPoint(0, 1), rect.topRight() + QPoint(0, 1));
                } else {
                    painter->drawLine(rect.bottomLeft(), rect.bottomRight());
                    painter->setPen(lighter);
                    painter->drawLine(rect.topLeft(), rect.topRight());
                }
            } else {
                painter->drawLine(rect.topLeft(), rect.bottomLeft());
                painter->drawLine(rect.topRight(), rect.bottomRight());
            }
        }
        break;

    default:

        QProxyStyle::drawControl(element, option, painter, widget);
        break;
    }
}

void ManhattanStyle::drawComplexControl(ComplexControl control, const QStyleOptionComplex *option,
                                        QPainter *painter, const QWidget *widget) const
{
    if (!panelWidget(widget))
         return QProxyStyle::drawComplexControl(control, option, painter, widget);

    QRect rect = option->rect;
    switch (control) {
    case CC_ToolButton:
        if (const QStyleOptionToolButton *toolbutton = qstyleoption_cast<const QStyleOptionToolButton *>(option)) {
            bool reverse = option->direction == Qt::RightToLeft;
            bool drawborder = (widget && widget->property("showborder").toBool());

            if (drawborder)
                drawButtonSeparator(painter, rect, reverse);

            QRect button, menuarea;
            button = subControlRect(control, toolbutton, SC_ToolButton, widget);
            menuarea = subControlRect(control, toolbutton, SC_ToolButtonMenu, widget);

            State bflags = toolbutton->state;
            if (bflags & State_AutoRaise) {
                if (!(bflags & State_MouseOver))
                    bflags &= ~State_Raised;
            }

            State mflags = bflags;
            if (toolbutton->state & State_Sunken) {
                if (toolbutton->activeSubControls & SC_ToolButton)
                    bflags |= State_Sunken;
                if (toolbutton->activeSubControls & SC_ToolButtonMenu)
                    mflags |= State_Sunken;
            }

            QStyleOption tool(0);
            tool.palette = toolbutton->palette;
            if (toolbutton->subControls & SC_ToolButton) {
                tool.rect = button;
                tool.state = bflags;
                drawPrimitive(PE_PanelButtonTool, &tool, painter, widget);
            }

            QStyleOptionToolButton label = *toolbutton;

            label.palette = panelPalette(option->palette, lightColored(widget));
            if (widget && widget->property("highlightWidget").toBool())
                label.palette.setColor(QPalette::ButtonText, Qt::red);
            int fw = pixelMetric(PM_DefaultFrameWidth, option, widget);
            label.rect = button.adjusted(fw, fw, -fw, -fw);

            drawControl(CE_ToolButtonLabel, &label, painter, widget);

            if (toolbutton->subControls & SC_ToolButtonMenu) {
                tool.state = mflags;
                tool.rect = menuarea.adjusted(1, 1, -1, -1);
                if (mflags & (State_Sunken | State_On | State_Raised)) {
                    painter->setPen(Qt::gray);
                    painter->drawLine(tool.rect.topLeft(), tool.rect.bottomLeft());
                    if (mflags & (State_Sunken)) {
                        QColor shade(0, 0, 0, 50);
                        painter->fillRect(tool.rect.adjusted(0, -1, 1, 1), shade);
                    } else if ( (mflags & State_MouseOver)) {
                        QColor shade(255, 255, 255, 50);
                        painter->fillRect(tool.rect.adjusted(0, -1, 1, 1), shade);
                    }
                }
                tool.rect = tool.rect.adjusted(2, 2, -2, -2);
                drawPrimitive(PE_IndicatorArrowDown, &tool, painter, widget);
            } else if (toolbutton->features & QStyleOptionToolButton::HasMenu
                       && widget && !widget->property("noArrow").toBool()) {
                int arrowSize = 6;
                QRect ir = toolbutton->rect.adjusted(1, 1, -1, -1);
                QStyleOptionToolButton newBtn = *toolbutton;
                newBtn.palette = panelPalette(option->palette);
                newBtn.rect = QRect(ir.right() - arrowSize - 1,
                                    ir.height() - arrowSize - 2, arrowSize, arrowSize);
                drawPrimitive(PE_IndicatorArrowDown, &newBtn, painter, widget);
            }
        }
        break;

    case CC_ComboBox:
        if (const QStyleOptionComboBox *cb = qstyleoption_cast<const QStyleOptionComboBox *>(option)) {
            painter->save();
            bool isEmpty = cb->currentText.isEmpty() && cb->currentIcon.isNull();
            bool reverse = option->direction == Qt::RightToLeft;
            bool drawborder = !(widget && widget->property("hideborder").toBool());
            bool drawleftborder = (widget && widget->property("drawleftborder").toBool());
            bool alignarrow = !(widget && widget->property("alignarrow").toBool());

            if (drawborder) {
                drawButtonSeparator(painter, rect, reverse);
                if (drawleftborder)
                    drawButtonSeparator(painter, rect.adjusted(0, 0, -rect.width() + 2, 0), reverse);
            }

            QStyleOption toolbutton = *option;
            if (isEmpty)
                toolbutton.state &= ~(State_Enabled | State_Sunken);
            painter->save();
            if (drawborder) {
                int leftClipAdjust = 0;
                if (drawleftborder)
                    leftClipAdjust = 2;
                painter->setClipRect(toolbutton.rect.adjusted(leftClipAdjust, 0, -2, 0));
            }
            drawPrimitive(PE_PanelButtonTool, &toolbutton, painter, widget);
            painter->restore();

            int menuButtonWidth = 12;
            int left = !reverse ? rect.right() - menuButtonWidth : rect.left();
            int right = !reverse ? rect.right() : rect.left() + menuButtonWidth;
            QRect arrowRect((left + right) / 2 + (reverse ? 6 : -6), rect.center().y() - 3, 9, 9);

            if (!alignarrow) {
                int labelwidth = option->fontMetrics.width(cb->currentText);
                if (reverse)
                    arrowRect.moveLeft(qMax(rect.width() - labelwidth - menuButtonWidth - 2, 4));
                else
                    arrowRect.moveLeft(qMin(labelwidth + menuButtonWidth - 2, rect.width() - menuButtonWidth - 4));
            }
            if (option->state & State_On)
                arrowRect.translate(QProxyStyle::pixelMetric(PM_ButtonShiftHorizontal, option, widget),
                                    QProxyStyle::pixelMetric(PM_ButtonShiftVertical, option, widget));

            QStyleOption arrowOpt = *option;
            arrowOpt.rect = arrowRect;
            if (isEmpty)
                arrowOpt.state &= ~(State_Enabled | State_Sunken);

            if (styleHint(SH_ComboBox_Popup, option, widget)) {
                arrowOpt.rect.translate(0, -3);
                drawPrimitive(PE_IndicatorArrowUp, &arrowOpt, painter, widget);
                arrowOpt.rect.translate(0, 6);
                drawPrimitive(PE_IndicatorArrowDown, &arrowOpt, painter, widget);
            } else {
                drawPrimitive(PE_IndicatorArrowDown, &arrowOpt, painter, widget);
            }

            painter->restore();
        }
        break;

    default:
        QProxyStyle::drawComplexControl(control, option, painter, widget);
        break;
    }
}

void ManhattanStyle::drawButtonSeparator(QPainter *painter, const QRect &rect, bool reverse) const
{
    QLinearGradient grad(rect.topRight(), rect.bottomRight());
    grad.setColorAt(0, QColor(255, 255, 255, 20));
    grad.setColorAt(0.4, QColor(255, 255, 255, 60));
    grad.setColorAt(0.7, QColor(255, 255, 255, 50));
    grad.setColorAt(1, QColor(255, 255, 255, 40));
    painter->setPen(QPen(grad, 0));
    painter->drawLine(rect.topRight(), rect.bottomRight());
    grad.setColorAt(0, QColor(0, 0, 0, 30));
    grad.setColorAt(0.4, QColor(0, 0, 0, 70));
    grad.setColorAt(0.7, QColor(0, 0, 0, 70));
    grad.setColorAt(1, QColor(0, 0, 0, 40));
    painter->setPen(QPen(grad, 0));
    if (!reverse)
       painter->drawLine(rect.topRight() - QPoint(1,0), rect.bottomRight() - QPoint(1,0));
    else
       painter->drawLine(rect.topLeft(), rect.bottomLeft());
 }

/////////////////

QPainterPath ManhattanStyle::createArcPath(const QStyleOption *option, int r) const
{
    const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option);
    int tabShape = tab->shape;
    QRect rect = tab->rect;

    QPoint firstPoint;
    QPoint firstPoint_four;
    QPoint firstPoint_sec;
    QPoint c2;
    QPainterPath arcPath;

    if (tabShape == QTabBar::TriangularNorth || tabShape == QTabBar::RoundedNorth || tabShape == QTabBar::TriangularSouth || tabShape == QTabBar::RoundedSouth){
        firstPoint = rect.topLeft();
        firstPoint_four = QPoint(firstPoint.x(), firstPoint.y() + r);
        firstPoint_sec = QPoint(firstPoint.x() + r, firstPoint.y());

        arcPath = QPainterPath(firstPoint_four);
        arcPath.arcTo(firstPoint.x(), firstPoint.y(), 2 * r, 2 * r, 180, -90);
        arcPath.lineTo(firstPoint_sec);
    }
    else if (tabShape == QTabBar::TriangularWest || tabShape == QTabBar::RoundedWest){

        firstPoint = rect.topLeft();
        firstPoint_four = QPoint(firstPoint.x() + r, firstPoint.y());
        firstPoint_sec = QPoint(firstPoint.x(), firstPoint.y() + r);


        arcPath = QPainterPath(firstPoint_four);
        arcPath.arcTo(firstPoint.x(), firstPoint.y(), 2 * r, 2 * r, 90, 90);
        arcPath.lineTo(firstPoint_sec);
    }
    else if (tabShape == QTabBar::TriangularEast || tabShape == QTabBar::RoundedEast){
        firstPoint = rect.topRight();
        firstPoint_four = QPoint(firstPoint.x() - r, firstPoint.y());
        firstPoint_sec = QPoint(firstPoint.x(), firstPoint.y() + r);

        arcPath = QPainterPath(firstPoint_four);
        arcPath.arcTo(firstPoint.x() - 2 * r, firstPoint.y(), 2 * r, 2 * r, 90, -90);
        arcPath.lineTo(firstPoint_sec);
    }
    return arcPath;
}

void ManhattanStyle::paintTabs(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option);
    if (element == CE_TabBarTabLabel)
    {
        QRect * pRect = (QRect*)(const QRect*)&option->rect;
        int tabShape = tab->shape;
        if (tabShape == QTabBar::TriangularNorth || tabShape == QTabBar::RoundedNorth || tabShape == QTabBar::TriangularSouth || tabShape == QTabBar::RoundedSouth){
            pRect->setLeft(option->rect.left() - 30);
        }
        else if (tabShape == QTabBar::TriangularWest || tabShape == QTabBar::RoundedWest || tabShape == QTabBar::TriangularEast || tabShape == QTabBar::RoundedEast){
            pRect->setTop(option->rect.top() - 30);
        }

    }
    else if (element == CE_TabBarTabShape){

        int r = 7;
        bool selected = tab->state & State_Selected;
        bool onlyOne = tab->position == QStyleOptionTab::OnlyOneTab;
        bool isBegin = tab->position == QStyleOptionTab::Beginning;
        bool isEnd = tab->position == QStyleOptionTab::End;
        bool isNextIsSelected = tab->selectedPosition == QStyleOptionTab::NextIsSelected;
        int tabOverlap = onlyOne ? 0 : proxy()->pixelMetric(PM_TabBarTabOverlap, option, widget);
        int tabShape = tab->shape;

        QRect rect = tab->rect;
        //if (false == selected)
        //    rect.adjust(0, 0, 0, -1);

        painter->setRenderHint(QPainter::Antialiasing);

        QPoint firstPoint;
        QPoint firstPoint_four;
        QPoint firstPoint_sec;
        QPoint secondPoint;
        QPoint thirdPoint;
        QPoint fourPoint;

        QPoint startPoint;
        QPoint endPoint;
        QPoint c1;
        QPoint c2;
        QPainterPath path;

        if (tabShape == QTabBar::TriangularNorth || tabShape == QTabBar::RoundedNorth || tabShape == QTabBar::TriangularSouth || tabShape == QTabBar::RoundedSouth){
            firstPoint = rect.topLeft();
            firstPoint_four = QPoint(firstPoint.x(), firstPoint.y() + r);
            firstPoint_sec = QPoint(firstPoint.x() + r, firstPoint.y());
            secondPoint = rect.topRight();
            thirdPoint = rect.bottomRight();
            fourPoint = rect.bottomLeft();

            startPoint = QPoint(rect.right() - m_width, rect.top());
            endPoint = QPoint(rect.right(), rect.bottom());
            c1 = QPoint((startPoint + endPoint).x() / 2, startPoint.y());
            c2 = QPoint((startPoint + endPoint).x() / 2, endPoint.y());

            path = QPainterPath(fourPoint);
            path.lineTo(firstPoint_four);
            path.arcTo(firstPoint.x(), firstPoint.y(), 2 * r, 2 * r, 180, -90);
            path.lineTo(startPoint);
            path.cubicTo(c1, c2, endPoint);
        }
        else if (tabShape == QTabBar::TriangularWest || tabShape == QTabBar::RoundedWest){

            firstPoint = rect.topLeft();
            firstPoint_four = QPoint(firstPoint.x() + r, firstPoint.y());
            firstPoint_sec = QPoint(firstPoint.x(), firstPoint.y() + r);
            secondPoint = rect.bottomLeft();
            thirdPoint = rect.bottomRight();
            fourPoint = rect.topRight();

            startPoint = QPoint(rect.left(), rect.bottom() - m_width);
            endPoint = QPoint(rect.right(), rect.bottom());
            c1 = QPoint(startPoint.x(), (startPoint + endPoint).y() / 2);
            c2 = QPoint(endPoint.x(), (startPoint + endPoint).y() / 2);

            path = QPainterPath(fourPoint);
            path.lineTo(firstPoint_four);
            path.arcTo(firstPoint.x(), firstPoint.y(), 2 * r, 2 * r, 90, 90);
            path.lineTo(startPoint);
            path.cubicTo(c1, c2, endPoint);
        }
        else if (tabShape == QTabBar::TriangularEast || tabShape == QTabBar::RoundedEast){
            firstPoint = rect.topRight();
            firstPoint_four = QPoint(firstPoint.x() - r, firstPoint.y());
            firstPoint_sec = QPoint(firstPoint.x(), firstPoint.y() + r);
            secondPoint = rect.bottomRight();
            thirdPoint = rect.bottomLeft();
            fourPoint = rect.topLeft();

            startPoint = QPoint(rect.right(), rect.bottom() - m_width);
            endPoint = QPoint(rect.left(), rect.bottom());
            c1 = QPoint(startPoint.x(), (startPoint + endPoint).y() / 2);
            c2 = QPoint(endPoint.x(), (startPoint + endPoint).y() / 2);

            path = QPainterPath(fourPoint);
            path.lineTo(firstPoint_four);
            path.arcTo(firstPoint.x() - 2 * r, firstPoint.y(), 2 * r, 2 * r, 90, -90);
            path.lineTo(startPoint);
            path.cubicTo(c1, c2, endPoint);
        }


        QLinearGradient gradient(firstPoint, fourPoint);
        gradient.setColorAt(0, 0xFFFFFF);
        gradient.setColorAt(0.3, 0xFFFFFF);
        gradient.setColorAt(0.4, 0xF9F9F9);
        gradient.setColorAt(1, 0x9C9990);

        QLinearGradient selgradient1(firstPoint, fourPoint);
        selgradient1.setColorAt(0, 0xE18A76);
        selgradient1.setColorAt(0.15, 0xE18A76);
        selgradient1.setColorAt(0.3, 0xDE8470);
        selgradient1.setColorAt(0.45, 0xE18A76);
        selgradient1.setColorAt(1, 0x8C3925);


		if (onlyOne || isEnd){
            QPainterPath backPath(fourPoint);
            backPath.lineTo(firstPoint);
            backPath.lineTo(startPoint);
            backPath.cubicTo(c1, c2, endPoint);
            painter->fillPath(backPath, QBrush(gradient));
        }
        else{
            QRect tempRect(rect.x(), rect.y(), rect.width(), rect.height() + 1);
            painter->fillRect(tempRect, QBrush(gradient));
        }


        if (option->state & QStyle::State_Selected){

            painter->fillPath(path, QBrush(selgradient1));
        }

        painter->setBrush(QBrush());
        QPen pen(0x949A94);
        painter->setPen(pen);

        if (!isBegin){
            painter->drawLine(firstPoint, firstPoint_sec);
        }

        if (isBegin || option->state & QStyle::State_Selected){
            painter->drawLine(fourPoint, firstPoint_four);
            painter->drawPath(createArcPath(option, r));
        }
        painter->drawLine(firstPoint_sec, startPoint);
        if (isNextIsSelected){
            painter->drawLine(startPoint, secondPoint);
        }
        else{
            QPainterPath path(startPoint);
            path.cubicTo(c1, c2, endPoint);
            painter->drawPath(path);
			if (!onlyOne && !isEnd){
				painter->drawLine(startPoint, secondPoint);
			}
        }

        return;
    }

    QProxyStyle::drawControl(element, option, painter, widget);
}

QSize ManhattanStyle::sizeFromContentsTab(ContentsType type, const QStyleOption *option,
    const QSize &size, const QWidget *widget) const
{
    QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);
    if (type == QStyle::CT_TabBarTab)
    {
        const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option);
        int tabShape = tab->shape;
        if (tabShape == QTabBar::TriangularNorth || tabShape == QTabBar::RoundedNorth || tabShape == QTabBar::TriangularSouth || tabShape == QTabBar::RoundedSouth){
            s.rwidth() = s.width() + m_width;
            s.setHeight(23);
        }
        else if (tabShape == QTabBar::TriangularWest || tabShape == QTabBar::RoundedWest || tabShape == QTabBar::TriangularEast || tabShape == QTabBar::RoundedEast){
            s.setWidth(23);
            s.setHeight(s.height() + m_width);
        }
    }

    return s;
}
/*
void CustomTabStyle::drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    paintTabs(element, option, painter, widget);
// 	QProxyStyle::drawControl(element, option, painter, widget);
}

QPainterPath CustomTabStyle::createPath(const QStyleOption *option, const int r)
{
    const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option);
    int tabShape = tab->shape;
    QRect rect = tab->rect;

    QPoint firstPoint;
    QPoint firstPoint_four;
    QPoint firstPoint_sec;
    QPoint secondPoint;
    QPoint thirdPoint;
    QPoint fourPoint;

    QPoint startPoint;
    QPoint endPoint;
    QPoint c1;
    QPoint c2;
    QPainterPath path;

    if (tabShape == QTabBar::TriangularNorth || tabShape == QTabBar::RoundedNorth || tabShape == QTabBar::TriangularSouth || tabShape == QTabBar::RoundedSouth){
        firstPoint = rect.topLeft();
        firstPoint_four = QPoint(firstPoint.x(), firstPoint.y() + r);
        firstPoint_sec = QPoint(firstPoint.x() + r, firstPoint.y());
        secondPoint = rect.topRight();
        thirdPoint = rect.bottomRight();
        fourPoint = rect.bottomLeft();

        startPoint = QPoint(rect.right() - m_width, rect.top());
        endPoint = QPoint(rect.right(), rect.bottom());
        c1 = QPoint((startPoint + endPoint).x() / 2, startPoint.y());
        c2 = QPoint((startPoint + endPoint).x() / 2, endPoint.y());

        path = QPainterPath(fourPoint);
        path.lineTo(firstPoint_four);
        path.arcTo(firstPoint.x(), firstPoint.y(), 2 * r, 2 * r, 180, -90);
        path.lineTo(startPoint);
        path.cubicTo(c1, c2, endPoint);
    }
    else if (tabShape == QTabBar::TriangularWest || tabShape == QTabBar::RoundedWest){

        firstPoint = rect.topLeft();
        firstPoint_four = QPoint(firstPoint.x() + r, firstPoint.y());
        firstPoint_sec = QPoint(firstPoint.x(), firstPoint.y() + r);
        secondPoint = rect.bottomLeft();
        thirdPoint = rect.bottomRight();
        fourPoint = rect.topRight();

        startPoint = QPoint(rect.left(), rect.bottom() - m_width);
        endPoint = QPoint(rect.right(), rect.bottom());
        c1 = QPoint(startPoint.x(), (startPoint + endPoint).y() / 2);
        c2 = QPoint(endPoint.x(), (startPoint + endPoint).y() / 2);

        path = QPainterPath(fourPoint);
        path.lineTo(firstPoint_four);
        path.arcTo(firstPoint.x(), firstPoint.y(), 2 * r, 2 * r, 90, 90);
        path.lineTo(startPoint);
        path.cubicTo(c1, c2, endPoint);
    }
    else if (tabShape == QTabBar::TriangularEast || tabShape == QTabBar::RoundedEast){
        firstPoint = rect.topRight();
        firstPoint_four = QPoint(firstPoint.x() - r, firstPoint.y());
        firstPoint_sec = QPoint(firstPoint.x(), firstPoint.y() + r);
        secondPoint = rect.bottomRight();
        thirdPoint = rect.bottomLeft();
        fourPoint = rect.topLeft();

        startPoint = QPoint(rect.right(), rect.bottom() - m_width);
        endPoint = QPoint(rect.left(), rect.bottom());
        c1 = QPoint(startPoint.x(), (startPoint + endPoint).y() / 2);
        c2 = QPoint(endPoint.x(), (startPoint + endPoint).y() / 2);

            path = QPainterPath(fourPoint);
            path.lineTo(firstPoint_four);
            path.arcTo(firstPoint.x() - 2 * r, firstPoint.y(), 2 * r, 2 * r, 90, -90);
            path.lineTo(startPoint);
            path.cubicTo(c1, c2, endPoint);
    }
    return path;
}
*/
