#include <QPainter>

#include "calendarmanager.h"

CalendarManager::CalendarManager(QWidget *parent)
    : QCalendarWidget(parent)
{
    m_outlinePen.setColor(Qt::red);
    m_transparentBrush.setColor(Qt::transparent);

    getDates();
}

CalendarManager::~CalendarManager()
{

}

void CalendarManager::setColor(const QColor &color)
{
    m_outlinePen.setColor(color);
}

QColor CalendarManager::getColor() const
{
    return ( m_outlinePen.color() );
}

void CalendarManager::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    QCalendarWidget::paintCell(painter, rect, date);

    if( m_dates.contains(date) ) {
        painter->setPen(m_outlinePen);
        painter->setBrush(m_transparentBrush);
        painter->drawRect(rect.adjusted(0, 0, -1, -1));
    }
}

void CalendarManager::getDates()
{
    QFile file("/data/events.csv");
    if(!file.open(QIODevice::ReadOnly)) {
        //Error code
    }

    QList<QByteArray> wordList;

    QDate date;
    QString name;
    calendarEvent e;

    while(!file.atEnd()) {
        QByteArray line = file.readLine();
        wordList = line.split(',');

        date = QDate::fromString( wordList.first(), "dd/MM/yyyy" );
        name = wordList.last();

        e.date = date;
        e.name = name;

        m_events.append(e);
        m_dates.append(date);
    }

    file.close();
}
