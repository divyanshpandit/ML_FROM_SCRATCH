#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    const char *filename = "exercise_with_calories.csv";
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return 1;
    }

    // Allocate dynamic arrays for Duration (x) and Calories (y)
    size_t capacity = 100;
    size_t size = 0;
    double *x_vals = malloc(capacity * sizeof(double));
    double *y_vals = malloc(capacity * sizeof(double));
    if (!x_vals || !y_vals) {
        fprintf(stderr, "Error: memory allocation failed\n");
        return 1;
    }

    // Read header line and ignore
    char line[1024];
    if (!fgets(line, sizeof(line), file)) {
        fprintf(stderr, "Error: empty file\n");
        return 1;
    }

    // Parse each line: skip to column 5 (Duration) and 8 (Calories)
    while (fgets(line, sizeof(line), file)) {
        // Remove newline characters from line
        line[strcspn(line, "\r\n")] = 0;

        // Skip empty lines
        if (strlen(line) == 0) continue;

        // Tokenize by comma
        char *token = strtok(line, ",");
        int col = 0;
        double duration = 0.0, calories = 0.0;
        while (token != NULL) {
            if (col == 5) { 
                duration = atof(token);
            }
            if (col == 8) {
                calories = atof(token);
                break;  // We've got both values; exit loop
            }
            token = strtok(NULL, ",");
            col++;
        }
        // Ensure we found both values
        if (col < 8) continue;

        // Resize arrays if needed
        if (size >= capacity) {
            capacity *= 2;
            x_vals = realloc(x_vals, capacity * sizeof(double));
            y_vals = realloc(y_vals, capacity * sizeof(double));
            if (!x_vals || !y_vals) {
                fprintf(stderr, "Error: memory reallocation failed\n");
                return 1;
            }
        }
        x_vals[size] = duration;
        y_vals[size] = calories;
        size++;
    }
    fclose(file);

    if (size == 0) {
        fprintf(stderr, "Error: no data found\n");
        return 1;
    }

    // Initialize parameters
    double w = 0.0, b = 0.0;
    double learning_rate = 0.0001;
    int epochs = 1000;

    // Gradient descent training
    for (int epoch = 1; epoch <= epochs; epoch++) {
        double sum_error = 0.0;
        double dw_sum = 0.0;
        double db_sum = 0.0;
        // Compute gradients and cost
        for (size_t i = 0; i < size; i++) {
            double x = x_vals[i];
            double y = y_vals[i];
            double pred = w * x + b;
            double err = pred - y;
            sum_error += err * err;
            dw_sum += err * x;
            db_sum += err;
        }
        double cost = sum_error / size;  // MSE
        // Compute gradients (include factor 2/n for MSE cost)
        double dw = (2.0 / size) * dw_sum;
        double db = (2.0 / size) * db_sum;
        // Update parameters
        w -= learning_rate * dw;
        b -= learning_rate * db;

        // Print every 100 epochs
        if (epoch % 100 == 0) {
            printf("Epoch %d: cost = %.4f, w = %.4f, b = %.4f\n", 
                   epoch, cost, w, b);
        }
    }

    // Free training data arrays
    free(x_vals);
    free(y_vals);

    // Predict on user input
    double input_duration;
    printf("Enter duration: ");
    if (scanf("%lf", &input_duration) == 1) {
        double predicted_cal = w * input_duration + b;
        printf("Predicted calories burned: %.2f\n", predicted_cal);
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}
