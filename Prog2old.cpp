#include <fstream>
#include <iostream>
#include <string>
#include <vector>




int main() {
  std::fstream fin("file.txt", std::fstream::in);
  std::fstream buffer("file.txt", std::fstream::in);  // buffer looks ahead
  std::vector<std::string> lexeme{};                  // vector of all lexemes from input

  char ch{};
  char bch{};
  std::string word{};

  buffer.get(bch);  // buffer stays ahead by one char
  while (buffer.get(bch)) {
    fin.get(ch);
    switch (ch) {
      case ' ':
        if (word != "") {
          lexeme.push_back(word);
          word = "";
        }
        break;
      
      case '=': case ',': case ';': case '+': case '-': case '*':
        if (word != "") {
          lexeme.push_back(word);
        }
        word += ch;
        lexeme.push_back(word);
        word = "";
        break;

      case '/':
        if (word != "") {
          lexeme.push_back(word);
          word = "";
        }
        if (bch == '/') {
          while (ch != '\n') {
            fin.get(ch);
            buffer.get(bch);
          }
          break;
        }
        word += ch;
        lexeme.push_back(word);
        word = "";
        break;

      case 'c':
        word += ch;

        fin.get(ch);
        buffer.get(bch);
        
        if (ch == 'i') {
          word += ch;
          fin.get(ch);
          buffer.get(bch);
          if (bch == 'n') {
            word += ch;
            fin.get(ch);
            buffer.get(bch);
            if (bch == '>') {
              wo
            }
          }
        }

        else {

        }
        break;

        

      default:
        word += ch;
        break;
    }
  }

  fin.get(ch);
  if (ch != ' ') {
    word += ch;
    lexeme.push_back(word);
  }

  ch = 47;
  std::cout << ch;
  return 0;
}