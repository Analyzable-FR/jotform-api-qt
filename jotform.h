#ifndef JOTFORM_H
#define JOTFORM_H

#include <QEventLoop>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QObject>
#include <QUrlQuery>

class Jotform : public QObject {
  Q_OBJECT
 public:
  explicit Jotform(QObject *parent = nullptr);
  Jotform(const QByteArray &apiKey, QObject *parent = nullptr);
  void setApiKey(const QString &apiKey);

  QJsonDocument getUser();
  QJsonDocument getUserUsage();
  QJsonDocument getUserSubmissions();
  QJsonDocument getSubusers();
  QJsonDocument getUserFolders();
  QJsonDocument getUserReports();
  QJsonDocument getUserLogout();
  QJsonDocument getUserSettings();
  QJsonDocument getUserHistory();
  QJsonDocument getUserForms();
  QJsonDocument getForm(const QString &id);
  QJsonDocument getFormQuestions(const QString &id);
  QJsonDocument getFormQuestionsDetails(const QString &id,
                                        const QString &detail);
  QJsonDocument getFormProperties(const QString &id);
  QJsonDocument getFormPropertie(const QString &id, const QString &property);
  QJsonDocument getFormReports(const QString &id);
  QJsonDocument getFormFiles(const QString &id);
  QJsonDocument getFormWebhooks(const QString &id);
  QJsonDocument getFormSubmissions(const QString &id);
  QJsonDocument getSubmission(const QString &id);
  QJsonDocument getReport(const QString &id);
  QJsonDocument getFolder(const QString &id);
  QJsonDocument getSystemPlan(const QString &name);

 private:
  QNetworkAccessManager *manager;
  QJsonDocument processRequest(QNetworkReply *reply);
  QJsonDocument sendRequest(const QString &req,
                            const QMap<QString, QString> &data,
                            const QString &method);
  QString baseUrl;
  QByteArray apiKey;
 signals:
};
#endif  // JOTFORM_H
