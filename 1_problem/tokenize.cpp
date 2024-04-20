#include "tokenize.h"
#include <unordered_map>

std::vector<std::string_view> ParseName(const std::string_view &str) {
  std::vector<std::string_view> res;
  std::string_view delimiter = " ";
  size_t begin = 0;
  size_t end = str.find(delimiter);
  while (begin < str.size()) {
    if (begin != end) {
      size_t space = (end == str.size()) ? end : end - begin;
      res.emplace_back(str.substr(begin, space));
    }
    begin = (end >= str.size() ? end : end + delimiter.size());
    end = str.find(delimiter, begin);
  }
  return res;
}

bool IsNumber(std::string_view str) {
  if (!isdigit(str[0]) && str[0] != '-' && str[0] != '+') {
    return false;
  }
  if (str.size() == 1 && !isdigit(str[0])) {
    return false;
  }
  size_t index = (str[0] == '-' || str[0] == '+') ? 1 : 0;
  while (index < str.size() && isdigit(str[index])) {
    index++;
  }
  return index == str.size();
}

Token ToToken(std::string_view str) {
  const std::unordered_map<std::string_view, Token> kSymbol2Token{
      {"(", OpeningBracketToken{}}, {")", ClosingBracketToken{}},
      {"+", PlusToken{}}, {"-", MinusToken{}},
      {"*", MultiplyToken{}}, {"/", DivideToken{}},
      {"%", ModuloToken{}}, {"min", MinToken{}},
      {"max", MaxToken{}}, {"abs", AbsToken{}},
      {"sqr", SqrToken{}}};
  if (IsNumber(str)) {
    char *end{};
    return NumberToken{std::strtoll(str.data(),&end, 10)};
  }
  if (auto it = kSymbol2Token.find(str); it != kSymbol2Token.end()) {
    return it->second;
  }
  return UnknownToken{std::string(str)};
}
std::vector<Token> Tokenize(const std::string &input) {
  std::vector<std::string_view> separated = ParseName(input);
  std::vector<Token> tokens;
  tokens.reserve(separated.size());
  for (auto &str : separated) {
    tokens.emplace_back(ToToken(str));
  }
  return tokens;
}