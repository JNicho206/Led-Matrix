#include <Matrix.h>

Matrix::Matrix() {}

bool Matrix::isEdge(int r, int c, int direction) 
{
    switch (direction)
    {
    case UPLEFT:
        if (r == 7 || c == 0)
        {
            return true;
        }
        else
        {
            return false;
        }

        break;

    case UP:
        if (r == 7)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    case UPRIGHT:
        if (r == 7 || c == 7)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    case RIGHT:
        if (c == 7)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    case DOWNRIGHT:
        if (r == 0 || c == 7)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    case DOWN:
        if (r == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    case DOWNLEFT:
        if (r == 0 || c == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    case LEFT:
        if (c == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;

    default:
        break;

    }
}

int Matrix::adjacent(int origin, int direction)
{
    int row = origin / 8;
    int col = origin % 8;

    switch (direction)
    {
        case UPLEFT:
            if (isEdge(row, col, direction))
            {
                return -1;
            }
            else
            {
                return row * 8 + col;
            }
            break;

        case UP:
            if (isEdge(row, col, direction))
            {
                return -1;
            }
            else
            {
                return row * 8 + col;
            }
            break;

        case UPRIGHT:
            if (isEdge(row, col, direction))
            {
                return -1;
            }
            else
            {
                return row * 8 + col;
            }
            break;

        case RIGHT:
            if (isEdge(row, col, direction))
            {
                return -1;
            }
            else
            {
                return row * 8 + col;
            }
            break;

        case DOWNRIGHT:
            if (isEdge(row, col, direction))
            {
                return -1;
            }
            else
            {
                return row * 8 + col;
            }
            break;

        case DOWN:
            if (isEdge(row, col, direction))
            {
                return -1;
            }
            else
            {
                return row * 8 + col;
            }
            break;

        case DOWNLEFT:
            if (isEdge(row, col, direction))
            {
                return -1;
            }
            else
            {
                return row * 8 + col;
            }
            break;

        case LEFT:
            isEdge(row, col, direction);
            break;

    }
}