#ifndef S21_MATRIX_
#define S21_MATRIX_

// для сравнения матриц
#define SUCCESS 1
#define FAILURE 0

// для остальных
#define OK 0
#define ERROR_MATRIX 1
#define ERROR_CALC 2

// структура матрицы
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

/*
rows - количество строк
columns - количество столбцов
result - указатель на структуру - результат выполнения
number - число
A - указатель на первую структуру
B - указатель на вторую структуру
*/

// создать матрицу
int s21_create_matrix(int rows, int columns, matrix_t *result);

// удалить матрицу
void s21_remove_matrix(matrix_t *A);

// сравнение матриц
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// сложение и вычитание матриц
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// умножение матрицы на число или матрицу
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// транспонирование матрицы (замена строк ее столбцами)
int s21_transpose(matrix_t *A, matrix_t *result);

// минор матрицы и матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result);

// определитель матрицы
int s21_determinant(matrix_t *A, double *result);

// обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif // S21_MATRIX_