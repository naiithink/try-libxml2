#ifndef MYXML
#define MYXML

#include <libxml2/libxml/nanohttp.h>
#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/tree.h>

namespace Tree
{
    typedef struct __Node
    {
        unsigned long childCound;
        char *elem;
        char *attr;
        struct __Node *parent;
        struct __Node *child;
        struct __Node *next;
    }
    Node;
};

// Utils
int containChar (const char *str);
int fetchFile (const char * URL, const char * filename, char ** contentType);

// initMode
// 0 : bispoken
// 1 : estimated
class MyTree
{
    public:
        explicit MyTree (const int initMode = 0);
        explicit MyTree (const int initMode = 1,
                         const unsigned long levelCount = 0,
                         const unsigned long nodeCount_max = 0);
        int initTree (Tree::Node *pTreeRoot,
                      const unsigned long levelCount = 0,
                      const unsigned long nodeCount_max = 0);
        int inspectTree (Tree::Node *pTreeRoot);
        // choose algo: this->treeWeight
        int countThisNode (Tree::Node *pTreeRoot);
        int exportTree2Text (const char *desPath);
        unsigned long childCount (Tree::Node *pTreeNode);
        int freeTree (void);

    protected:
        int initMode;
        // treeWeight
        // 0: balanced
        // 1: right -- upper
        // 2: left -- lower
        int treeWeight;
        Tree::Node *pTreeRoot;
};

// MyXML
class MyXML
{
    public:
        explicit MyXML (const char *filepath);
        // preorder traversal
        void fprintNode (FILE * __restrict __stream,
                         xmlNodePtr pNode = NULL,
                         const int indent = 0);
        void fprintTree (FILE * __restrict __stream,
                         const int indent = 0);
        unsigned long getArity (void);
        void closeDoc (void);
        // ~MyXML (void);

    protected:
        xmlDocPtr pDoc;
        xmlNodePtr pRootNode;
        const char *filepath;
        unsigned long arity;
        unsigned long levelCount;
        unsigned long nodeCount_max;
        unsigned long nodeCount_leaves;
        xmlDocPtr initDoc (const char *filepath);
        xmlNodePtr getRootNodePtr (const xmlDocPtr pDoc);
};

// MyHTML
class MyHTML : public MyXML
{
    public:
        explicit MyHTML (const char *filepath);
        // ~MyHTML (void);
};

#endif