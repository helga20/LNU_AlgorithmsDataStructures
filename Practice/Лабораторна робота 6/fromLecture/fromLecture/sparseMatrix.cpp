#include "sparseMatrix.h"
#include <iostream>
using namespace std;

    SparseMatrix::SparseMatrix()
    {
        for (int i = 0; i <= rows_quantity; i++)
        {
            rows[i].left = &rows[i];
        }

        for (size_t j = 0; j <= columns_quantity; j++)
        {
            cols[j].up = &cols[j];
        }
    }

    Element* SparseMatrix::get_previous_by_row(int row_number, int column_number)
    {
        Element* current = &rows[row_number];
        while (current->left->column_number > column_number)
        {
            current = current->left;
        }
        return current;
    };

    Element* SparseMatrix::get_previous_by_column(int row_number, int column_number)
    {
        Element* current = &cols[column_number];
        while (current->up->row_number > row_number)
        {
            current = current->up;
        }
        return current;
    }

    void SparseMatrix::remove_element(int row_number, int column_number)
    {
        Element* prev_by_row = get_previous_by_row(row_number, column_number);
        Element* prev_by_col = get_previous_by_column(row_number, column_number);

        Element* current = prev_by_row->left;
        //checking if element is already in matrix
        if (current->column_number == column_number)
        {
            prev_by_row->left = current->left;
            prev_by_col->up = current->up;
            delete current;
        }
    }


    void SparseMatrix::add_element(int row_number, int column_number, int value)
    {
        Element* prev_by_row = get_previous_by_row(row_number, column_number);
        Element* prev_by_col = get_previous_by_column(row_number, column_number);
        Element* new_element = new Element();
        new_element->row_number = row_number;
        new_element->column_number = column_number;
        new_element->value = value;

        new_element->left = prev_by_row->left;
        prev_by_row->left = new_element;

        new_element->up = prev_by_col->up;
        prev_by_col->up = new_element;
    }

    int SparseMatrix::get_element(int row_number, int column_number)
    {
        Element* prev_by_row = get_previous_by_row(row_number, column_number);
        Element* current = prev_by_row->left;
        int return_value = 0;
        if (current->column_number == column_number)
        {
            return_value = current->value;
        }
        return return_value;
    }

