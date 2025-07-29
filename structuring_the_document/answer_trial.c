#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
	char* data;
};

struct sentence {
	struct word* data;
	int word_count;	 // denotes number of words in a sentence
};

struct paragraph {
	struct sentence* data;
	int sentence_count;	 // denotes number of sentences in a paragraph
};

struct document {
	struct paragraph* data;
	int paragraph_count;  // denotes number of paragraphs in a document
};

// Example test case
char* text = "This is a sample document.It contains multiple sentences and paragraphs.\nEach sentence has multiple words.And each paragraph has multiple sentences.";

int main() {
	// We don't want to ruin original text
	char* raw = strdup(text);

	// First allocations
	struct document doc;

	// paragraph
	doc.paragraph_count = 0;
	doc.data			= NULL;

	char* save_p;
	char* p = strtok_r(raw, "\n", &save_p);

	while (p != NULL) {
		doc.paragraph_count++;
		doc.data  = realloc(doc.data, doc.paragraph_count * sizeof(struct paragraph));
		int p_idx = doc.paragraph_count - 1;

		doc.data[p_idx].sentence_count = 0;
		doc.data[p_idx].data		   = NULL;

		char* tmp_p = strdup(p);  // Duplicate the original paragraph for
		char* save_s;
		char* s = strtok_r(tmp_p, ".", &save_s);

		printf("Paragraph %d: %s\n", doc.paragraph_count, p);

		while (s != NULL) {
			int s_idx			 = doc.data[p_idx].sentence_count++;
			doc.data[p_idx].data = realloc(doc.data[p_idx].data,
										   doc.data[p_idx].sentence_count * sizeof(struct sentence));

			doc.data[p_idx].data[s_idx].word_count = 0;
			doc.data[p_idx].data[s_idx].data	   = NULL;

			char* tmp_s = strdup(s);
			char* save_w;
			char* w = strtok_r(tmp_s, " ", &save_w);

			printf(" Sentence %d: %s\n", doc.data[p_idx].sentence_count, s);

			while (w != NULL) {
				int w_idx						 = doc.data[p_idx].data[s_idx].word_count++;
				doc.data[p_idx].data[s_idx].data = realloc(
					doc.data[p_idx].data[s_idx].data,
					doc.data[p_idx].data[s_idx].word_count * sizeof(struct word));

				doc.data[p_idx].data[s_idx].data[w_idx].data = malloc(strlen(w) + 1);
				strcpy(doc.data[p_idx].data[s_idx].data[w_idx].data, w);

				printf("  Word %d: %s\n", doc.data[p_idx].data[s_idx].word_count, doc.data[p_idx].data[s_idx].data[w_idx].data);

				w = strtok_r(NULL, " ", &save_w);
			}

			free(tmp_s);
			s = strtok_r(NULL, ".", &save_s);
		}

		free(tmp_p);
		p = strtok_r(NULL, "\n", &save_p);
	}

	free(raw);
	return 0;
}
