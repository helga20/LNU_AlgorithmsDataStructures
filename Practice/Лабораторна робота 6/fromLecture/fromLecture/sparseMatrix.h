#pragma once
class Element
{
public:
    int row_number;
    int column_number;
    int value;
    Element* up;
    Element* left;
    Element()
    {
        row_number = 0;
        column_number = 0;
        up = left = nullptr;
    }
};

class SparseMatrix
{
    static const int rows_quantity = 10;
    static const int columns_quantity = 10;
    Element rows[rows_quantity + 1];
    Element cols[columns_quantity + 1];
public:
    SparseMatrix();
    Element* get_previous_by_row(int row_number, int column_number);
    Element* get_previous_by_column(int row_number, int column_number);
    void remove_element(int row_number, int column_number);
    void add_element(int row_number, int column_number, int value);
    int get_element(int row_number, int column_number);
};

