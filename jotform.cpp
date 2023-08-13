#include "jotform.h"

Jotform::Jotform(QObject *parent)
    : QObject{parent},
      apiKey{apiKey},
      manager{new QNetworkAccessManager(this)},
      baseUrl{"https://api.jotform.com/"} {
  connect(manager, &QNetworkAccessManager::finished, this,
          &Jotform::processRequest);
}

Jotform::Jotform(const QByteArray &apiKey, QObject *parent)
    : Jotform(parent = parent) {
  setApiKey(apiKey);
}

void Jotform::setApiKey(const QByteArray &apiKey) { this->apiKey = apiKey; }

void Jotform::processRequest(QNetworkReply *reply) {}

void Jotform::sendRequest(const QString &req,
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

  QNetworkRequest request = QNetworkRequest();
  request.setRawHeader("apiKey", this->apiKey);
  request.setRawHeader("User-Agent", "JOTFORM_PYTHON_WRAPPER");

  if (method == "GET") {
    url.setQuery(query.query());
    request.setUrl(url);
    manager->get(request);
  } else if (method == "POST") {
    QByteArray data = url.toString().toUtf8();
    manager->post(request, data);
  } else if (method == "PUT") {
    QByteArray data = url.toString().toUtf8();
    manager->put(request, data);
  } else if (method == "DELETE") {
    manager->deleteResource(request);
  }
}
