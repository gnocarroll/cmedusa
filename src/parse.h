#ifndef PARSE_H
#define PARSE_H

#include <stddef.h>

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

struct ParsedModule {
    
};

DEF_PARSER_LIST_NODE(Module)

#endif // PARSE_H