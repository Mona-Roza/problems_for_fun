#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* my_strdup(const char* s) {
	char* copy = malloc(strlen(s) + 1);
	if (copy != NULL)
		strcpy(copy, s);
	return copy;
}

#define strdup my_strdup

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
	return document[n - 1][m - 1][k - 1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
	return document[m - 1][k - 1];
}

char*** kth_paragraph(char**** document, int k) {
	return document[k - 1];
}

char**** get_document(char* text) {
	// We don't want to ruin original text
	char* raw = strdup(text);

	// allocate memory
	char**** doc = malloc(MAX_PARAGRAPHS * sizeof(char***));

	int p = 0, s = 0, w = 0;

	// Seperate paragraphs
	char* save_p;
	char* paragraphs = strtok_r(raw, "\n", &save_p);
	while (paragraphs != NULL) {
		doc[p] = malloc(MAX_CHARACTERS * sizeof(char**));

		// You have whole paragraphs pointer. Start to exploring sentence.
		char* tmp_p = strdup(paragraphs);
		char* save_s;
		char* sentences = strtok_r(tmp_p, ".", &save_s);

		while (sentences != NULL) {
			doc[p][s] = malloc(MAX_CHARACTERS * sizeof(char*));

			char* tmp_s = strdup(sentences);
			char* save_w;
			char* words = strtok_r(tmp_s, " ", &save_w);

			while (words != NULL) {
				doc[p][s][w] = malloc(MAX_CHARACTERS * sizeof(char));

				strcpy(doc[p][s][w], words);

				w++;
				words = strtok_r(NULL, " ", &save_w);
			}

			w = 0;
			free(tmp_s);
			s++;
			sentences = strtok_r(NULL, ".", &save_s);
		}
		s = 0;
		free(tmp_p);
		p++;
		paragraphs = strtok_r(NULL, "\n", &save_p);
	}

	return doc;
}

char* get_input_text() {
	int paragraph_count;
	scanf("%d", &paragraph_count);

	char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
	memset(doc, 0, sizeof(doc));
	getchar();
	for (int i = 0; i < paragraph_count; i++) {
		scanf("%[^\n]%*c", p[i]);
		strcat(doc, p[i]);
		if (i != paragraph_count - 1)
			strcat(doc, "\n");
	}

	char* returnDoc = (char*)malloc((strlen(doc) + 1) * (sizeof(char)));
	strcpy(returnDoc, doc);
	return returnDoc;
}

void print_word(char* word) {
	printf("%s", word);
}

void print_sentence(char** sentence) {
	int word_count;
	scanf("%d", &word_count);
	for (int i = 0; i < word_count; i++) {
		printf("%s", sentence[i]);
		if (i != word_count - 1)
			printf(" ");
	}
}

void print_paragraph(char*** paragraph) {
	int sentence_count;
	scanf("%d", &sentence_count);
	for (int i = 0; i < sentence_count; i++) {
		print_sentence(*(paragraph + i));
		printf(".");
	}
}

int main() {
	char* text		  = get_input_text();
	char**** document = get_document(text);

	int q;
	scanf("%d", &q);

	while (q--) {
		int type;
		scanf("%d", &type);

		if (type == 3) {
			int k, m, n;
			scanf("%d %d %d", &k, &m, &n);
			char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
			print_word(word);
		}

		else if (type == 2) {
			int k, m;
			scanf("%d %d", &k, &m);
			char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
			print_sentence(sentence);
		}

		else {
			int k;
			scanf("%d", &k);
			char*** paragraph = kth_paragraph(document, k);
			print_paragraph(paragraph);
		}
		printf("\n");
	}
}