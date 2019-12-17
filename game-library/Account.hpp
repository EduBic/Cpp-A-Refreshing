#include <string>
#include "list/List.hpp"

class Account
{
public:
    
    Account(std::string nickName) : _nickName(nickName), _gameLibrary() {}
    
    const std::string getNickName() const
    {
        return _nickName;
    } 

    void addGame(const std::string& gameName)
    {
        _gameLibrary.push_back(gameName);
    }

private:
    std::string _nickName;
    List<std::string> _gameLibrary;
};