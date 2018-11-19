


#ifndef CMANHATTANSTYLE_H
#define CMANHATTANSTYLE_H 

#include "Global.h"

#include <QProxyStyle>

void qt_blurImage(QPainter *p, QImage &blurImage, qreal radius, bool quality, bool alphaOnly, int transposed = 0);

class Animation
{
public :
    Animation() : m_running(true) { }
    virtual ~Animation() { }
    QWidget * widget() const { return m_widget; }
    bool running() const { return m_running; }
    const QTime &startTime() const { return m_startTime; }
    void setRunning(bool val) { m_running = val; }
    void setWidget(QWidget *widget) { m_widget = widget; }
    void setStartTime(const QTime &startTime) { m_startTime = startTime; }
    virtual void paint(QPainter *painter, const QStyleOption *option);

protected:
    void drawBlendedImage(QPainter *painter, const QRect &rect, float value);
    QTime m_startTime;
    QPointer<QWidget> m_widget;
    QImage m_primaryImage;
    QImage m_secondaryImage;
    QImage m_tempImage;
    bool m_running;
};


class Transition : public Animation
{
public :
    Transition() : Animation(), m_duration(100) {}
    virtual ~Transition() {}
    void setDuration(int duration) { m_duration = duration; }
    void setStartImage(const QImage &image) { m_primaryImage = image; }
    void setEndImage(const QImage &image) { m_secondaryImage = image; }
    virtual void paint(QPainter *painter, const QStyleOption *option);
    int duration() const { return m_duration; }
    int m_duration;
};

class StyleAnimator : public QObject
{
    Q_OBJECT

public:
    StyleAnimator(QObject *parent = 0) : QObject(parent) {}

    void timerEvent(QTimerEvent *);
    void startAnimation(Animation *);
    void stopAnimation(const QWidget *);
    Animation* widgetAnimation(const QWidget *) const;

private:
    QBasicTimer animationTimer;
    QList <Animation*> animations;
};

class ThemePrivate;

class DLL_CLASS Theme : public QObject
{
    Q_OBJECT

    Q_ENUMS(Color)
    Q_ENUMS(ImageFile)
    Q_ENUMS(Gradient)
    Q_ENUMS(Flag)
    Q_ENUMS(WidgetStyle)

public:
    Theme(const QString &name, QObject *parent = 0);
    ~Theme();

    enum Color {
        BackgroundColorAlternate,
        BackgroundColorDark,
        BackgroundColorHover,
        BackgroundColorNormal,
        BackgroundColorSelected,
        BadgeLabelBackgroundColorChecked,
        BadgeLabelBackgroundColorUnchecked,
        BadgeLabelTextColorChecked,
        BadgeLabelTextColorUnchecked,
        CanceledSearchTextColor,
        ComboBoxArrowColor,
        ComboBoxArrowColorDisabled,
        ComboBoxTextColor,
        DetailsWidgetBackgroundColor,
        DetailsButtonBackgroundColorHover,
        DockWidgetResizeHandleColor,
        DoubleTabWidget1stEmptyAreaBackgroundColor,
        DoubleTabWidget1stSeparatorColor,
        DoubleTabWidget2ndSeparatorColor,
        DoubleTabWidget1stTabBackgroundColor,
        DoubleTabWidget2ndTabBackgroundColor,
        DoubleTabWidget1stTabActiveTextColor,
        DoubleTabWidget1stTabInactiveTextColor,
        DoubleTabWidget2ndTabActiveTextColor,
        DoubleTabWidget2ndTabInactiveTextColor,
        EditorPlaceholderColor,
        FancyTabBarBackgroundColor,
        FancyTabWidgetEnabledSelectedTextColor,
        FancyTabWidgetEnabledUnselectedTextColor,
        FancyTabWidgetDisabledSelectedTextColor,
        FancyTabWidgetDisabledUnselectedTextColor,
        FancyToolButtonHoverColor,
        FancyToolButtonSelectedColor,
        FutureProgressBackgroundColor,
        MenuBarEmptyAreaBackgroundColor,
        MenuBarItemBackgroundColor,
        MenuBarItemTextColorDisabled,
        MenuBarItemTextColorNormal,
        MiniProjectTargetSelectorBackgroundColor,
        MiniProjectTargetSelectorBorderColor,
        MiniProjectTargetSelectorSummaryBackgroundColor,
        MiniProjectTargetSelectorTextColor,
        OutputPaneButtonFlashColor,
        OutputPaneToggleButtonTextColorChecked,
        OutputPaneToggleButtonTextColorUnchecked,
        PanelButtonToolBackgroundColorHover,
        PanelTextColorLight,
        PanelTextColorDark,
        PanelsWidgetSeparatorLineColor,
        PanelStatusBarBackgroundColor,
        ProgressBarTitleColor,
        ProgressBarColorError,
        ProgressBarColorFinished,
        ProgressBarColorNormal,
        InfoBarBackground,
        InfoBarText,
        TextColorDisabled,
        TextColorHighlight,
        TextColorNormal,
        TodoItemTextColor,
        ToggleButtonBackgroundColor,
        ToolBarBackgroundColor,
        TreeViewArrowColorNormal,
        TreeViewArrowColorSelected,

        OutputFormatter_NormalMessageTextColor,
        OutputFormatter_ErrorMessageTextColor,
        OutputFormatter_StdOutTextColor,
        OutputFormatter_StdErrTextColor,
        OutputFormatter_DebugTextColor,

        QtOutputFormatter_LinkTextColor,



        Welcome_TextColorNormal,
        Welcome_TextColorHeading,
        Welcome_BackgroundColorNormal,
        Welcome_DividerColor,
        Welcome_Button_BorderColorNormal,
        Welcome_Button_BorderColorPressed,
        Welcome_Button_TextColorNormal,
        Welcome_Button_TextColorPressed,
        Welcome_Link_TextColorNormal,
        Welcome_Link_TextColorActive,
        Welcome_Link_BackgroundColor,
        Welcome_Caption_TextColorNormal,
        Welcome_SideBar_BackgroundColor,

        Welcome_ProjectItem_TextColorFilepath,
        Welcome_ProjectItem_BackgroundColorHover,

        Welcome_SessionItem_BackgroundColorNormal,
        Welcome_SessionItem_BackgroundColorHover,
        Welcome_SessionItemExpanded_BackgroundColorNormal,
        Welcome_SessionItemExpanded_BackgroundColorHover
    };

    enum Gradient {
        DetailsWidgetHeaderGradient,
        Welcome_Button_GradientNormal,
        Welcome_Button_GradientPressed
    };

    enum ImageFile {
        ProjectExplorerHeader,
        ProjectExplorerSource,
        ProjectExplorerForm,
        ProjectExplorerResource,
        ProjectExplorerQML,
        ProjectExplorerOtherFiles,
        ProjectFileIcon,
        IconOverlayCSource,
        IconOverlayCppHeader,
        IconOverlayCppSource,
        IconOverlayPri,
        IconOverlayPrf,
        IconOverlayPro,
        StandardPixmapFileIcon,
        StandardPixmapDirIcon
    };

    enum Flag {
        DrawTargetSelectorBottom,
        DrawSearchResultWidgetFrame,
        DrawProgressBarSunken,
        DrawIndicatorBranch,
        ComboBoxDrawTextShadow,
        DerivePaletteFromTheme,
        ApplyThemePaletteGlobally
    };

    enum WidgetStyle {
        StyleDefault,
        StyleFlat
    };

    WidgetStyle widgetStyle() const;
    bool flag(Flag f) const;
    QColor color(Color role) const;
    QString imageFile(ImageFile imageFile, const QString &fallBack) const;
    QGradientStops gradient(Gradient role) const;
    QPalette palette() const;
    QStringList preferredStyles() const;

    QString filePath() const;
    QString name() const;
    void setName(const QString &name);

    QVariantHash values() const;

    void writeSettings(const QString &filename) const;
    void readSettings(QSettings &settings);

    static QPalette initialPalette();

    ThemePrivate *d;

private:
    QPair<QColor, QString> readNamedColor(const QString &color) const;
};

DLL_CLASS Theme *creatorTheme();


class DLL_CLASS StyleHelper
{
public:
    static const unsigned int DEFAULT_BASE_COLOR = 0x666666;
    static const int progressFadeAnimationDuration = 600;


    static int navigationWidgetHeight() { return 24; }
    static qreal sidebarFontSize();
    static QPalette sidebarFontPalette(const QPalette &original);


    static QColor requestedBaseColor() { return m_requestedBaseColor; }
    static QColor baseColor(bool lightColored = false);
    static QColor panelTextColor(bool lightColored = false);
    static QColor highlightColor(bool lightColored = false);
    static QColor shadowColor(bool lightColored = false);
    static QColor borderColor(bool lightColored = false);
    static QColor buttonTextColor() { return QColor(0x4c4c4c); }
    static QColor mergedColors(const QColor &colorA, const QColor &colorB, int factor = 50);

    static QColor sidebarHighlight() { return QColor(255, 255, 255, 40); }
    static QColor sidebarShadow() { return QColor(0, 0, 0, 40); }

    static QColor notTooBrightHighlightColor();


    static void setBaseColor(const QColor &color);


    static void drawArrow(QStyle::PrimitiveElement element, QPainter *painter, const QStyleOption *option);


    static void horizontalGradient(QPainter *painter, const QRect &spanRect, const QRect &clipRect, bool lightColored = false);
    static void verticalGradient(QPainter *painter, const QRect &spanRect, const QRect &clipRect, bool lightColored = false);
    static void menuGradient(QPainter *painter, const QRect &spanRect, const QRect &clipRect);
    static bool usePixmapCache() { return true; }

    static void drawIconWithShadow(const QIcon &icon, const QRect &rect, QPainter *p, QIcon::Mode iconMode,
                                   int dipRadius = 3, const QColor &color = QColor(0, 0, 0, 130),
                                   const QPoint &dipOffset = QPoint(1, -2));
    static void drawCornerImage(const QImage &img, QPainter *painter, const QRect &rect,
                         int left = 0, int top = 0, int right = 0, int bottom = 0);

    static void tintImage(QImage &img, const QColor &tintColor);
    static QLinearGradient statusBarGradient(const QRect &statusBarRect);

    static QString dpiSpecificImageFile(const QString &fileName);

private:
    static QColor m_baseColor;
    static QColor m_requestedBaseColor;
};

class ManhattanStylePrivate;

class DLL_CLASS ManhattanStyle : public QProxyStyle
{
    Q_OBJECT

public:
    explicit ManhattanStyle(const QString &baseStyleName);

    ~ManhattanStyle();

    void drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = 0) const;
    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = 0) const;
    void drawComplexControl(ComplexControl control, const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget = 0) const;

    QSize sizeFromContents(ContentsType type, const QStyleOption *option, const QSize &size, const QWidget *widget) const;
    QRect subElementRect(SubElement element, const QStyleOption *option, const QWidget *widget) const;
    QRect subControlRect(ComplexControl cc, const QStyleOptionComplex *opt, SubControl sc, const QWidget *widget) const;

    SubControl hitTestComplexControl(ComplexControl control, const QStyleOptionComplex *option, const QPoint &pos, const QWidget *widget = 0) const;
    QPixmap standardPixmap(StandardPixmap standardPixmap, const QStyleOption *opt, const QWidget *widget = 0) const;
    int styleHint(StyleHint hint, const QStyleOption *option = 0, const QWidget *widget = 0, QStyleHintReturn *returnData = 0) const;
    QRect itemRect(QPainter *p, const QRect &r, int flags, bool enabled, const QPixmap *pixmap, const QString &text, int len = -1) const;
    QPixmap generatedIconPixmap(QIcon::Mode iconMode, const QPixmap &pixmap, const QStyleOption *opt) const;

    int pixelMetric(PixelMetric metric, const QStyleOption *option = 0, const QWidget *widget = 0) const;

    QPalette standardPalette() const;

    void polish(QWidget *widget);
    void polish(QPalette &pal);
    void polish(QApplication *app);

    void unpolish(QWidget *widget);
    void unpolish(QApplication *app);

protected slots:
    QIcon standardIconImplementation(StandardPixmap standardIcon, const QStyleOption *option, const QWidget *widget) const;

private:
    void drawButtonSeparator(QPainter *painter, const QRect &rect, bool reverse) const;
    QSize sizeFromContentsTab(ContentsType type, const QStyleOption *option,const QSize &size, const QWidget *widget) const;
    QPainterPath createArcPath(const QStyleOption *option, int r) const;
    void paintTabs(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    ManhattanStylePrivate *d;
    mutable int m_width;
};


//
/*
class DLL_CLASS CustomTabStyle : public QProxyStyle
{
    Q_OBJECT
private:
    mutable int m_width = 30;
    QPainterPath createArcPath(const QStyleOption *option, int r) const;
    void paintTabs(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
public:
    QSize sizeFromContents(ContentsType type, const QStyleOption *option,const QSize &size, const QWidget *widget) const;
    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;
    QPainterPath createPath(const QStyleOption *option, const int r);
};
*/
#endif
