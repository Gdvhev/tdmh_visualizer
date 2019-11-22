#ifndef LOGVISUAL_H
#define LOGVISUAL_H


#include <QPlainTextEdit>
#include <QWidget>
/*!
 * \brief The LogVisual class is a Widget that contains the text and adds line numbers
 */
class LogVisual : public QPlainTextEdit
{
    Q_OBJECT

public:
    /*!
     * \brief LogVisual builds a text edit that contains the log
     * \param parent the parent widget
     */
    LogVisual(QWidget *parent = nullptr);

    /*!
     * \brief lineNumberAreaPaintEvent draws the digits on the number column of the editor
     * \param event the paint event
     */
    void lineNumberAreaPaintEvent(QPaintEvent *event);

    /*!
     * \brief lineNumberAreaWidth calculates the width taken by the number area
     * \return the width taken by the number area
     */
    int lineNumberAreaWidth();

    /*!
     * \brief makeReady enables line change notification
     */
    void makeReady();

protected:
    /*!
     * \brief resizeEvent overrides standard resize event to account for line numers
     * \param event the resize event
     */
    void resizeEvent(QResizeEvent *event) override;




private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);
    /*!
     * \brief pushLine pushes a line to the Form
     * \param line the line to insert
     */
    void pushLine(const QString& line);

signals:
    /*!
     * \brief lineAdded signal to be raised to insert a new line
     * \param line the line to add
     */
    void lineAdded(const QString &line);

    /*!
     * \brief cursorChanged signal emitted when the cursor has changed not in response to a new line
     * \param lineN line number of the selected line
     */
    void cursorChanged(unsigned int lineN);

private:
    QWidget *lineNumberArea;
    bool ready=false;
    bool disableUpdate=true;
    int lastBlockNumber=0;

    // QWidget interface
protected:
    /*!
     * \brief mousePressEvent prevents left click from changing cursor position, sending a graph update request instead
     * \param event the mouse event
     */
    void mousePressEvent(QMouseEvent *event) override;

    /*!
     * \brief mouseDoubleClickEvent prevents the left double click from changing cursor position, sending a graph update request instead
     * \param event the mouse event
     */
    void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // LOGVISUAL_H
