#include "208.h"

Trie::Trie() :root(new TrieNode()) {
}

Trie::TrieNode::TrieNode() : children(26, NULL), word_end(false){
}

Trie::TrieNode::~TrieNode(){
	for (TrieNode* child : children)
		if (child)delete child;
}

const Trie::TrieNode* Trie::find(const string& word)const {
	TrieNode*p = root.get();
	for (const char& c : word) {
		int cur = c - 'a';
		p = p->children[cur];
		if (p == NULL)break;
	}
	return p;
}

void Trie::insert(string word) {
	TrieNode*p = root.get();
	for (const char& c : word) {
		int cur = c - 'a';
		if (p->children[cur] == NULL)p->children[cur] = new TrieNode();
		p = p->children[cur];
	}
	p->word_end = true;
}

bool Trie::search(string word) {
	const TrieNode* ret = this->find(word);
	if (ret != NULL && ret->word_end)return true;
	return false;
}

bool Trie::startsWith(string word) {
	if (this->find(word) != NULL)return true;
	return false;
}







/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/