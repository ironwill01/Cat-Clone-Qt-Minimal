#ifndef FLAGS_HPP
#define FLAGS_HPP

#include <memory>
#include <QString>

class QCommandLineParser;
class QCoreApplication;

/**
 * @brief An struct to hold what user passed into commandline 
 * 
 */
struct CLIOptions {
    QString filePath = QString();
    QString wordToRemove = QString();
    QString wordToColor = QString();
    bool showLines = false;
    bool removeChars = false;
    bool colorWords = false;
};

/**
 * @brief Create the parser class with its options and return it
 * 
 * @return std::unique_ptr<QCommandLineParser> 
 */
std::unique_ptr<QCommandLineParser> flagsInit(const QCoreApplication & app);

/**
 * @brief Create an CLIOptions to hold what user passed into program
 * 
 * @return std::unique_ptr<CLIOptions> 
 */
std::unique_ptr<CLIOptions> optionsInit(QCommandLineParser & parser);

#endif //FLAGS_HPP