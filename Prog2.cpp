#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::fstream fin("file.txt", std::fstream::in);
  std::fstream buffer("file.txt", std::fstream::in);  // buffer looks ahead
  std::vector<std::string> lexeme{};                  // vector of all lexemes scanned

  char state{};
  char ch{};
  char buffchar{};
  std::string word{};
  buffer.get(buffchar); // buffer = next char from ch

  while (fin.get(ch)) {

    buffer.get(buffchar);
    switch(ch) {
      //goto state
      case '=': case '+': case '-': case '*': case ',':
        state = 'D';
        break;

      case ';':
        state = 'C';
        break;

      //goto state
      case '/':
        state = 'F';
        break;

      //goto state
      case '\n':
        state = 'G';
        break;

      //goto state
      case ' ':
        state = 'A';
        break;

      //goto state
      default:
        state = 'B';
        break;

    }

    switch(state) {

      //action
      case 'A': 
        if (word != "") {
          lexeme.push_back(word);
          std::cout << word << ' ';
          word = "";
        }
        break;

      //action
      case 'D':
        if (word != "") {
          lexeme.push_back(word);
          std::cout << word << ' ';
          word = "";
        }
        word += ch;
        lexeme.push_back(word);
        std::cout << word << ' ';
        word = "";
        break;

      //action
      case 'B':
        word += ch;
        break;

      //action
      case 'C':
        if (word != "") {
          lexeme.push_back(word);
          std::cout << word << ' ';
          word = "";
        }
        word += ch;
        lexeme.push_back(word);
        std::cout << word << ' ';
        word = "";
        std::cout << '\n';
        break;

      //action
      case 'F':
        if (word != "") {
          lexeme.push_back(word);
          std::cout << word << ' ';
          word = "";
        }
        if (buffchar != '/') {
          word += ch;
          lexeme.push_back(word);
          std::cout << word << ' ';
          word = "";
        }

        if (buffchar == '/') {
          while (fin.get(ch)) {
            buffer.get(buffchar);
            
            if (ch == '\n') {
              state = 'A';
              break;
            }
          }
        }
        break;

      //action
      case 'G':
        if (word != "") {
          lexeme.push_back(word);
          std::cout << word << ' ';
          word = "";
        }
        word += ch;
        lexeme.push_back(word);
        word = "";
        while(fin.get(ch)) {
          buffer.get(buffchar);
          if (buffchar != '\n') {
            break;
          }
        }
        break;

      //action
      default:
        //dead state
        break;
    }
  }

  return 0;
}