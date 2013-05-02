#ifndef ReceiveR_H
#define ReceiveR_H

#include <QObject>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include "request.h"
#include <QStringList>
#include <QDateTime>

class Receiver : public QTcpServer
{
    Q_OBJECT

public:
    Receiver(QObject* parent = 0)
        : QTcpServer(parent), disabled(false)
    {
        listen(QHostAddress::Any, 8369);
    }

    void incomingConnection(int socket)
    {
        if (disabled)
            return;
        QTcpSocket* s = new QTcpSocket(this);
        connect(s, SIGNAL(readyRead()), this, SLOT(readClient()));
        connect(s, SIGNAL(disconnected()), this, SLOT(discardClient()));
        s->setSocketDescriptor(socket);
    }

    void pause()
    {
        disabled = true;
    }

    void resume()
    {
        disabled = false;
    }

signals:
    void signalRequestReceived(Request* req);

private slots:
    void readClient()
    {
        if (disabled)
            return;
        QTcpSocket* socket = (QTcpSocket*)sender();
        if (socket->canReadLine()) {
            QStringList tokens = QString(socket->readLine()).split(QRegExp("[ /-\r\n]+"));
            if (tokens[0] == "GET") {
                Request* req = new Request(tokens[1].toInt(),tokens[2].toInt());
                QTextStream os(socket);
                os.setAutoDetectUnicode(true);
                if(req->getDeparture()!=0&&req->getDestination()!=0){
                    os << "HTTP/1.0 200 Ok\r\n"
                          "Content-Type: text/html; charset=\"utf-8\"\r\n"
                          "\r\n"
                          "<h1>Request Received From Floor#"<<req->getDeparture()<<" to #"<<req->getDestination()<<"</h1>\n"
                       << QDateTime::currentDateTime().toString() << "\n";
                    emit signalRequestReceived(req);
                }else{
                    os << "HTTP/1.0 200 Ok\r\n"
                          "Content-Type: text/html; charset=\"utf-8\"\r\n"
                          "\r\n"
                          "<h1>Opps! Bad Request<br/>Usage:<br/>http://&lt;Hostname&gt;:8369/&lt;FloorFrom&gt;-&lt;FloorTo&gt;</h1>\n"
                       << QDateTime::currentDateTime().toString() << "\n";
                    delete req;
                }
                socket->close();
                if (socket->state() == QTcpSocket::UnconnectedState) {
                    delete socket;
                }
            }
        }
    }

    void discardClient()
    {
        QTcpSocket* socket = (QTcpSocket*)sender();
        socket->deleteLater();
    }

private:
    bool disabled;
};

#endif // ReceiveR_H
