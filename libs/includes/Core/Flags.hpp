#ifndef FLAGS_HPP
#define FLAGS_HPP

#include <memory>

class QString;
class QCommandLineParser;

std::unique_ptr<QCommandLineParser> flagsInit();

#endif //FLAGS_HPP