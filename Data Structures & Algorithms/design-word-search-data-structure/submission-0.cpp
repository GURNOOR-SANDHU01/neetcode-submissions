class WordDictionary {
private:

    class Node {
    public:
        Node* children[26];
        bool isEnd;

        Node() {
            isEnd = false;

            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    Node* root;

    bool searchHelper(string& word, int index, Node* node) {

        // We reached the end of the word
        if (index == word.length()) {
            return node->isEnd;
        }

        char ch = word[index];

        // Case 1: Normal letter
        if (ch != '.') {

            int idx = ch - 'a';

            // No such character
            if (node->children[idx] == nullptr) {
                return false;
            }

            return searchHelper(
                word,
                index + 1,
                node->children[idx]
            );
        }

        // Case 2: '.'
        // Try every possible character
        for (int i = 0; i < 26; i++) {

            if (node->children[i] != nullptr) {

                if (searchHelper(
                        word,
                        index + 1,
                        node->children[i]
                    )) {
                    return true;
                }
            }
        }

        return false;
    }

public:

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {

        Node* current = root;

        for (char ch : word) {

            int index = ch - 'a';

            if (current->children[index] == nullptr) {
                current->children[index] = new Node();
            }

            current = current->children[index];
        }

        current->isEnd = true;
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
