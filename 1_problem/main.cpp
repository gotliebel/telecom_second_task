#include "tokenize.h"
#include <iostream>

inline std::ostream &operator<<(std::ostream &os,
                                const std::variant<NumberToken,
                                                   UnknownToken,
                                                   PlusToken,
                                                   MinusToken,
                                                   MultiplyToken,
                                                   DivideToken,
                                                   MinToken,
                                                   MaxToken,
                                                   AbsToken,
                                                   ModuloToken,
                                                   SqrToken,
                                                   OpeningBracketToken,
                                                   ClosingBracketToken> &t) {
  if (std::holds_alternative<PlusToken>(t)) {
    os << std::string("PlusToken ");
  } else if (std::holds_alternative<NumberToken>(t)) {
    os << std::string("NumberToken ");
  } else if (std::holds_alternative<UnknownToken>(t)) {
    os << std::string("UnknownToken ");
  } else if (std::holds_alternative<MinusToken>(t)) {
    os << std::string("MinusToken ");
  } else if (std::holds_alternative<MultiplyToken>(t)) {
    os << std::string("MultiplyToken ");
  } else if (std::holds_alternative<DivideToken>(t)) {
    os << std::string("DivideToken ");
  } else if (std::holds_alternative<MinToken>(t)) {
    os << std::string("MinToken ");
  } else if (std::holds_alternative<MaxToken>(t)) {
    os << std::string("MaxToken ");
  } else if (std::holds_alternative<AbsToken>(t)) {
    os << std::string("AbsToken ");
  } else if (std::holds_alternative<ModuloToken>(t)) {
    os << std::string("ModuloToken ");
  } else if (std::holds_alternative<SqrToken>(t)) {
    os << std::string("SqrToken ");
  } else if (std::holds_alternative<OpeningBracketToken>(t)) {
    os << std::string("OpeningBracketToken ");
  } else if (std::holds_alternative<ClosingBracketToken>(t)) {
    os << std::string("ClosingBracketToken ");
  } else {
    os << std::string("some error");
  }
  return os;
}

int main() {
  auto made = Tokenize("+ +1 ( ) () * / max sqr ");
  for (auto &som : made) {
    std::cout << som;
  }
  return 0;
}