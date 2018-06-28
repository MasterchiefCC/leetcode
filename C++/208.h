
#ifndef TRIE_H
#define TRIE_H
#include "mod.h"

class Trie {
public:
	/** Initialize your data structure here. */
	Trie();

	/** Inserts a word into the trie. */
	void insert(string word);

	/** Returns if the word is in the trie. */
	bool search(string word);

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix);

private:

	struct TrieNode {
		vector<TrieNode*>children;
		bool word_end;
		TrieNode();
		~TrieNode();
	};
	const TrieNode* find(const string& word) const;
	
	std::unique_ptr<TrieNode>root;

};

#endif // TRIE_H

