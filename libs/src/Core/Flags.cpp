#include <Flags.hpp>
#include <QFile>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDebug>
#include <memory>


std::unique_ptr<QCommandLineParser> flagsInit() {
    std::unique_ptr<QCommandLineParser> parser(new QCommandLineParser());

    parser->setApplicationDescription("Cat Clone like app");
    parser->addHelpOption();
    
    QCommandLineOption lineOPT(
        {"l" , "line"},
        "Enable the line of numbers"
    );

    QCommandLineOption charOPT(
        {"c" , "remove-char"},
        "Remove a character from lines"
    );

    QCommandLineOption wordOPT(
        {"w" , "word-highlight"} ,
        "Highlight a word while printing the lines"
    );

    for (auto &opt : {lineOPT, charOPT, wordOPT})
        parser->addOption(opt);

    return parser;
}