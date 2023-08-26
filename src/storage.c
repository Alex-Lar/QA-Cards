#include <jansson.h>
#include <stdio.h>

int main() {
  const char *json_file_path = "../idea-2.json";

  json_t *root;
  json_error_t error;

  root = json_load_file(json_file_path, 0, &error);
  if (!root) {
    fprintf(stderr, "Error parsing JSON: %s\n", error.text);
    return 1;
  }

  // Accessing flashcard data
  json_t *cards = json_object_get(root, "cards");
  json_t *card;

  const char *card_id;
  json_object_foreach(cards, card_id, card) {
    const char *question = json_string_value(json_object_get(card, "question"));
    const char *answer = json_string_value(json_object_get(card, "answer"));

    printf("Card ID: %s\n", card_id);
    printf("Question: %s\n", question);
    printf("Answer: %s\n", answer);

    json_t *topics = json_object_get(card, "topics");
    if (json_is_array(topics)) {
      printf("Topics: ");
      size_t index;
      json_t *topic;
      json_array_foreach(topics, index, topic) {
        const char *topic_name = json_string_value(topic);
        printf("%s ", topic_name);
      }
      printf("\n");
    }

    printf("\n");
  }

  // Accessing topic data
  json_t *topics = json_object_get(root, "topics");
  const char *topic_name;
  json_t *topic;

  json_object_foreach(topics, topic_name, topic) {
    printf("Topic: %s\n", topic_name);

    printf("Card IDs: ");
    size_t index;
    json_t *card_id;
    json_array_foreach(topic, index, card_id) {
      const char *card_id_value = json_string_value(card_id);
      printf("%s ", card_id_value);
    }
    printf("\n\n");
  }

  json_decref(root);

  return 0;
}
