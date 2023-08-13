#ifndef JOTFORM_H
#define JOTFORM_H

#include <QNetworkAccessManager>
#include <QObject>
#include <QUrlQuery>

class Jotform : public QObject {
  Q_OBJECT
 public:
  explicit Jotform(QObject *parent = nullptr);
  Jotform(const QByteArray &apiKey, QObject *parent = nullptr);
  void setApiKey(const QByteArray &apiKey);

 private:
  QNetworkAccessManager *manager;
  void processRequest(QNetworkReply *reply);
  void sendRequest(const QString &req, const QMap<QString, QString> &data,
                   const QString &method);
  QString baseUrl;
  QByteArray apiKey;
 signals:
};

#endif  // JOTFORM_H
