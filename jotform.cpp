/**MIT License

Copyright (c) 2023 Analyzable | Benjamin Gallois

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#include "jotform.h"

Jotform::Jotform(QObject *parent)
    : QObject{parent},
      manager{new QNetworkAccessManager(this)},
      baseUrl{"https://eu-api.jotform.com/"} {}

Jotform::Jotform(const QByteArray &apiKey, QObject *parent)
    : Jotform(parent = parent) {
  setApiKey(apiKey);
}

void Jotform::setApiKey(const QString &apiKey) {
  this->apiKey = apiKey.toUtf8();
}

QJsonDocument Jotform::processRequest(QNetworkReply *reply) {
  QJsonDocument json_reply = QJsonDocument::fromJson(reply->readAll());
  return json_reply;
}

QJsonDocument Jotform::sendRequest(const QString &req,
                                   const QMap<QString, QString> &data,
                                   const QString &method) {
  QUrl url = QUrl(this->baseUrl + "v1" + req);

  QUrlQuery query;
  if (~data.isEmpty()) {
    QMapIterator<QString, QString> i(data);
    while (i.hasNext()) {
      i.next();
      query.addQueryItem(i.key(), i.value());
    }
  }

  QEventLoop eventLoop;
  QNetworkRequest request = QNetworkRequest();
  request.setRawHeader("apiKey", this->apiKey);
  request.setRawHeader("User-Agent", "JOTFORM_PYTHON_WRAPPER");
  QNetworkReply *reply;
  if (method == "GET") {
    url.setQuery(query.query());
    request.setUrl(url);
    reply = manager->get(request);
  } else if (method == "POST") {
    QByteArray data = url.toString().toUtf8();
    reply = manager->post(request, data);
  } else if (method == "PUT") {
    QByteArray data = url.toString().toUtf8();
    reply = manager->put(request, data);
  } else if (method == "DELETE") {
    reply = manager->deleteResource(request);
  }
  connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
  eventLoop.exec();
  QJsonDocument json_response = processRequest(reply);
  reply->deleteLater();
  return json_response;
}

QJsonDocument Jotform::getUser() {
  return sendRequest("/user", QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getUserUsage() {
  return sendRequest("/user/usage", QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getUserSubmissions() {
  return sendRequest("/user/submissions", QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getSubusers() {
  return sendRequest("/user/subusers", QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getUserFolders() {
  return sendRequest("/user/folders", QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getUserReports() {
  return sendRequest("/user/reports", QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getUserLogout() {
  return sendRequest("/user/logout", QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getUserSettings() {
  return sendRequest("/user/settings", QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getUserHistory() {
  return sendRequest("/user/history", QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getUserForms() {
  return sendRequest("/user/forms", QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getForm(const QString &id) {
  return sendRequest(QString("/form/%1").arg(id), QMap<QString, QString>(),
                     "GET");
}

QJsonDocument Jotform::getFormQuestions(const QString &id) {
  return sendRequest(QString("/form/%1/questions").arg(id),
                     QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getFormQuestionsDetails(const QString &id,
                                               const QString &questionId) {
  return sendRequest(QString("/form/%1/question/%2").arg(id, questionId),
                     QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getFormProperties(const QString &id) {
  return sendRequest(QString("/form/%1/properties").arg(id),
                     QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getFormPropertie(const QString &id,
                                        const QString &property) {
  return sendRequest(QString("/form/%1/properties/%2").arg(id, property),
                     QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getFormReports(const QString &id) {
  return sendRequest(QString("/form/%1/reports").arg(id),
                     QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getFormFiles(const QString &id) {
  return sendRequest(QString("/form/%1/files").arg(id),
                     QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getFormWebhooks(const QString &id) {
  return sendRequest(QString("/form/%1/webhooks").arg(id),
                     QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getFormSubmissions(const QString &id) {
  return sendRequest(QString("/form/%1/submissions").arg(id),
                     QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getSubmission(const QString &id) {
  return sendRequest(QString("/submission/%1").arg(id),
                     QMap<QString, QString>(), "GET");
}

QJsonDocument Jotform::getReport(const QString &id) {
  return sendRequest(QString("/report/%1").arg(id), QMap<QString, QString>(),
                     "GET");
}

QJsonDocument Jotform::getFolder(const QString &id) {
  return sendRequest(QString("/folder/%1").arg(id), QMap<QString, QString>(),
                     "GET");
}

QJsonDocument Jotform::getSystemPlan(const QString &name) {
  return sendRequest(QString("/system/plan/%1").arg(name),
                     QMap<QString, QString>(), "GET");
}
