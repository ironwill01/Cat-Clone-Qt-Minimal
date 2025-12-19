#ifndef CAT_HPP
#define CAT_HPP

#include <memory>

class QString;
class QFile;

/**
 * @brief Get the File object
 * 
 * @param path 
 * @return std::unique_ptr<QFile> 
 */
std::unique_ptr<QFile> getFile(const QString & path);

/**
 * @brief Main function to mimic the cat 
 * 
 * @param data 
 */
void catFile(const QString & data);


/**
 * @brief read the file till the end 
 * 
 * @param file 
 * @return true 
 * @return false 
 */
bool readFile(QFile & file);


#endif //CAT_HPP