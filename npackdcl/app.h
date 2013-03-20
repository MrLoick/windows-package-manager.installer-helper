#ifndef APP_H
#define APP_H

#include <time.h>

#include <QtCore/QCoreApplication>
#include <qdebug.h>
#include <qstringlist.h>
#include <qstring.h>

#include "..\wpmcpp\repository.h"
#include "..\wpmcpp\commandline.h"
#include "..\wpmcpp\job.h"
#include "..\wpmcpp\clprogress.h"

/**
 * NpackdCL
 */
class App: public QObject
{
    Q_OBJECT
private:
    CommandLine cl;
    CLProgress clp;

    void addNpackdCL();

    void usage();
    int path();
    int add();
    int remove();
    QString addRepo();
    QString removeRepo();
    QString search();
    int list();
    int info();
    int update();
    int detect();
    QString listRepos();
    QString which();

    /**
     * @param package full or short package name
     * @param err error message will be stored here
     * @return [ownership:caller] found package or 0
     */
    Package *findOnePackage(const QString &package, QString *err);
public:
    /**
     * Process the command line.
     *
     * @return exit code
     */
    int process();
};

#endif // APP_H
