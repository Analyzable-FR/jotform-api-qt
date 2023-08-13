#include <QCoreApplication>

#include "jotform.h"

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  Jotform api = Jotform();
  api.setApiKey("dsfdsdf");
  return a.exec();
}
