#ifndef TELECOM_SECOND_TASK_Token
#define TELECOM_SECOND_TASK_Token

#include <string>
#include <variant>
#include <vector>

struct NumberToken {
  int64_t value;
};

struct UnknownToken {
  std::string value;
};

struct OpeningBracketToken {};
struct ClosingBracketToken {};
struct PlusToken {};
struct MinusToken {};
struct MultiplyToken {};
struct DivideToken {};
struct ModuloToken {};
struct MinToken {};
struct MaxToken {};
struct AbsToken {};
struct SqrToken {};


using Token = std::variant<NumberToken, UnknownToken, PlusToken, MinusToken, MultiplyToken, DivideToken, MinToken,
                           MaxToken, AbsToken, ModuloToken, SqrToken, OpeningBracketToken, ClosingBracketToken>;

std::vector<Token> Tokenize(const std::string &input);

#endif
