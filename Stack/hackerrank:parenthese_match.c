// Problem: https://www.hackerrank.com/challenges/balanced-brackets/problem

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    char opposite;
    struct Node * next;
};

struct Stack {
    struct Node * head;
    int len;
};

void init_stack(struct Stack * st);
void push(struct Stack * st, char data);
char * pop(struct Stack * st);
int is_stack_empty(struct Stack * st);
char * decision_taker(char * str);


int main(void) {
    char * str[] = {
    "{()({}[[{}]]()(){[{{}{[[{}]{}((({[]}{}()[])))]((()()))}(()[[[]]])((()[[](({([])()}))[]]))}]})}",
    "()(){{}}[()()]{}{}",
    "{}()([[]])({}){({[][[][[()]]{{}[[]()]}]})}[](())((())[{{}}])",
    "{}(((){}){[]{{()()}}()})[]{{()}{(){()(){}}}}{()}({()(()({}{}()((()((([])){[][{()}{}]})))))})",
    "][[{)())))}[)}}}}[{){}()]([][]){{{{{[)}]]{([{)()][({}[){]({{",
    "{{}(",
    "{[{((({}{({({()})()})[]({()[[][][]]}){}}))){}}]}{}{({((){{}[][]{}[][]{}}[{}])(())}[][])}",
    "()[[][()[]][]()](([[[(){()[[]](([]))}]]]))",
    "()[]({}{})(()){{{}}()()}({[]()}())[](){}(({()}[{}[{({{}}){({}){({})((({()})))}}}]]))",
    "}[{){({}({)})]([}{[}}{[(([])[(}){[]])([]]}(]]]]{]["
    };
    for (int i=0; i<10; i++) {
        printf("[%d]: %s\n", i+1, decision_taker(str[i]));
    }
    return 0;
}

char * decision_taker(char * str) {
    struct Stack st;
    char * yes = "YES";
    char * no = "NO";
    init_stack(&st);
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            push(&st, str[i]);
        } else {
            char * popped = pop(&st);
            if (str[i] != popped[1])
            {
                return no;
            }
        }
        i++;
    }
    if (is_stack_empty(&st)) {
        return yes;
    }
    return no;
}

void init_stack(struct Stack * st) {
    st->head = NULL;
    st->len = 0;
}

struct Node * generate_node(char data) {
    struct Node * node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    if (node->data == '{') {
        node->opposite = '}';
    } else if (node->data == '[') {
        node->opposite = ']';
    } else if (node->data == '(') {
        node->opposite = ')';
    } else {
        node->opposite = 'x';
    }
    node->next = NULL;
    return node;
}

void push(struct Stack * st, char data) {
    struct Node * node = generate_node(data);
    if (st->head) {
        // stack not empty
        node->next = st->head;
        st->head = node;
        st->len++;
    }
    // stack empty
    st->head = node;
    st->len++;
}

char * pop(struct Stack * st) {
    char * output = (char *) malloc (2*sizeof(char));
    output[0] = 'x';
    output[1] = 'x';
    if (st->head) {
        output[0] = st->head->data;
        output[1] = st->head->opposite;
        st->head = st->head->next;
        st->len--;
    }
    return output;
}

int is_stack_empty(struct Stack * st) {
    // 1 --> empty, 0 --> not empty
    return (st->head)? 0 : 1;  
}
