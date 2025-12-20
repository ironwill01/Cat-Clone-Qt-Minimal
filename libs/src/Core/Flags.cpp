#include <Flags.hpp>
#include <QFile>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDebug>
#include <memory>


std::unique_ptr<QCommandLineParser> flagsInit(const QCoreApplication & app) {
    std::unique_ptr<QCommandLineParser> parser(new QCommandLineParser());

    parser->setApplicationDescription("Cat Clone like app");
    parser->addHelpOption();
    
    QCommandLineOption lineOPT(
        {"l" , "line"},
        "Enable the line of numbers"
    );

    QCommandLineOption charOPT(
        {"c" , "remove-char"},
        "Remove a character from lines",
        "char"
    );

    QCommandLineOption wordOPT(
        {"w" , "word-highlight"} ,
        "Highlight a word while printing the lines",
        "word"
    );

    for (auto &opt : {lineOPT, charOPT, wordOPT})
        parser->addOption(opt);

    parser->process(app);

    return parser;
}


std::unique_ptr<CLIOptions> optionsInit(QCommandLineParser & parser) {
    std::unique_ptr<CLIOptions> options = std::make_unique<CLIOptions>();

    options->showLines = parser.isSet("l");
    options->removeChars = parser.isSet("c");
    options->colorWords = parser.isSet("w");

    if(options->removeChars) {
        options->wordToRemove = parser.value("c");
    }

    if(options->colorWords) {
        options->wordToColor = parser.value("w");
    }

    options->filePath = parser.positionalArguments().last();

    return options; 
};