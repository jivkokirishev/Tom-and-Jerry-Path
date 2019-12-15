//
// Created by jivko on 14.12.19.
//

#include "InstructionsTree.h"

InstructionsTree::InstructionsTree(Node *tree) : tree(tree) {
}

void InstructionsTree::dottyPrint (std::ostream& out)
{
    out << "digraph G {" << std::endl;
    dottyPrintHelp (out, tree);
    out << "}";
}

void InstructionsTree::dottyPrintHelp (std::ostream& out, Node *current)
{

    if (current == nullptr)
    {
        return;
    }

    for (auto child : current->getChildren()) {
        out << (long)current << "->" << (long)child << std::endl;
        dottyPrintHelp(out, child);
    }


    out << (long)current << "[label=\"" << current->getData() << "\"];" << std::endl;
}
