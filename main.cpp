#include <QCoreApplication>

#include "jotform.h"

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  Jotform api = Jotform();
  api.setApiKey("SECRET");
  qInfo() << api.getUser() << "\n";
  qInfo() << api.getUserUsage() << "\n";
  qInfo() << api.getSubusers() << "\n";
  qInfo() << api.getUserLogout() << "\n";
  qInfo() << api.getUserSettings() << "\n";
  qInfo() << api.getUserHistory() << "\n";
  qInfo() << api.getUserForms() << "\n";
  qInfo() << api.getForm("232252927235354") << "\n";
  qInfo() << api.getFormQuestions("232252927235354") << "\n";
  qInfo() << api.getFormQuestionsDetails("232252927235354", "5") << "\n";
  qInfo() << api.getFormProperties("232252927235354") << "\n";
  qInfo() << api.getFormPropertie("232252927235354", "fontsize") << "\n";
  qInfo() << api.getFormReports("232252927235354") << "\n";
  qInfo() << api.getFormFiles("232252927235354") << "\n";
  qInfo() << api.getFormWebhooks("232252927235354") << "\n";
  qInfo() << api.getFormSubmissions("232252927235354") << "\n";
  qInfo() << api.getUserSubmissions() << "\n";
  qInfo() << api.getSubmission("5678225901025692465") << "\n";
  qInfo() << api.getUserReports() << "\n";
  qInfo() << api.getReport("0") << "\n";
  qInfo() << api.getUserFolders() << "\n";
  qInfo() << api.getFolder("64da1489636336981d63bf9d") << "\n";
  qInfo() << api.getSystemPlan("FREE") << "\n";
  return a.exec();
}
