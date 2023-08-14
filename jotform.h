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
