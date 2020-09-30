#include <iostream>
#include <sstream>
#include <vector>

bool parityCheck(int);

int main(int argc, char* argv[])
{
    int number{0};
    std::string message;
    std::vector<int> messageBytes;

    std::cout << "Please, input the message: ";
    std::getline(std::cin, message);

    std::stringstream str(message);
    while(!str.eof())
    {
        str >> number;
        messageBytes.push_back(number);
    }

    for (auto &number: messageBytes)
    {
        if(parityCheck(number))
        {
            if(number > 128) number -= 128;
            std::cout << static_cast<char>(number);
        }
    }

    std::cout << std::endl;

    return 0;
}

bool parityCheck(int messageByte)
{
    int bits{0};
    while (messageByte != 0)
    {
        if (messageByte % 2 == 0)
        {
            messageByte /= 2;
        }
        else if (messageByte == 1)
        {
            ++bits;
            break;
        }
        else
        {
            messageByte = (messageByte - 1)/2;
            ++bits;
        }
    }

    if (bits % 2 == 1) return false;

    return true;
}