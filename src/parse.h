#ifndef PARSE_H
#define PARSE_H

#include <stddef.h>

#include "types.h"

#define DEF_PARSER_LIST( Item ) \
    struct Parsed ## Item ## Node;\
    \
    typedef struct Parsed ## Item ## List { \
        struct Parsed ## Item ## Node *head;\
    } Parsed ## Item ## List;

#define DEF_PARSER_LIST_NODE( Item ) \
    typedef struct Parsed ## Item ## Node { \
        struct Parsed ## Item ## Node *next;\
        Parsed ## Item item;\
    } Parsed ## Item ## Node; \

struct ParsedProgram;

typedef struct ParseTree {
    struct ParsedProgram *prog;
} ParseTree;

struct ParsedModule;

DEF_PARSER_LIST(Module)

typedef struct ParsedProgram {
    ParsedModuleList modules;
} ParsedProgram;

struct ParsedFunctionDef;
struct ParsedTypeDef;
struct ParsedInstance;

DEF_PARSER_LIST(FunctionDef)
DEF_PARSER_LIST(TypeDef)
DEF_PARSER_LIST(Instance)

struct ParsedModule {
    ParsedFunctionDefList functions;
    ParsedTypeDefList types;
    ParsedInstanceList instances;
};

DEF_PARSER_LIST_NODE(Module)

struct ParsedStatement;

DEF_PARSER_LIST(Statement)

typedef struct ParsedFunctionDef {
    StrBounds name;
    StrBounds end_name;

    ParsedInstanceList params;
    ParsedStatementList statements;
} ParsedFunctionDef;

typedef enum TypeVariety {
    PARSED_SIGNED,
    PARSED_UNSIGNED,
    PARSED_FLOAT,
    PARSED_STRUCT,
} TypeVariety;

typedef struct ParsedTypeDef {
    TypeVariety variety;

    StrBounds name;

    ParsedInstanceList fields;
} ParsedTypeDef;

typedef struct ParsedInstance {
    StrBounds name;
} ParsedInstance;

DEF_PARSER_LIST_NODE(FunctionDef)
DEF_PARSER_LIST_NODE(TypeDef)
DEF_PARSER_LIST_NODE(Instance)

#endif // PARSE_H