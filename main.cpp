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
