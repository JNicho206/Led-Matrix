#include <Matrix.h>
#include <Pixel.h>

Matrix::Matrix(uint16_t w, uint16_t h, uint8_t pin) 
    : 
    size(MatrixSize(w, h)), 
    matrix(new Adafruit_NeoMatrix(int(w), int(h), pin, NEO_MATRIX_BOTTOM     + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                                                        NEO_GRB            + NEO_KHZ800))
{
    begin();
    setBrightness(20);
    clear();
}

void Matrix::begin()
{
    matrix->begin();
}
void Matrix::setBrightness(uint8_t b)
{
    matrix->setBrightness(b);
}

void Matrix::drawRainbow()
{
    clear();
    for (int i = 0; i < 64; i++)
    {
        setPixel(i, random(0, 200), random(0,200), random(0,200));
    }
    show();
}

void Matrix::drawRainbow(uint16_t totalTime, uint16_t delayTime)
{
    for (int n = 0; n < totalTime / delayTime; n++)
    {    
        clear();
        for (int i = 0; i < 64; i++)
        {
            setPixel(i, random(0, 200), random(0,200), random(0,200));
        }
        show();
        delay(delayTime);
    }
}

void Matrix::fireworks()
{
    //Maintain state of matrix inside object
    //Each pixel value
}

uint8_t Matrix::toSingle(const MatrixPair& p)
{
    const int cols = 8;
    uint8_t col;
    // Reverse the column index on every alternate row
    if (p.row % 2 == 1) {
        col = cols - 1 - p.col;
    }
    uint8_t single = p.row * cols + col;
    return single;
}

uint8_t Matrix::toSingle(pxind x, pxind y)
{
    const int cols = 8;
    uint8_t col;
    // Reverse the column index on every alternate row
    if (x % 2 == 1) {
        col = cols - 1 - y;
    }
    uint8_t single = x * cols + col;
    return single;
}

MatrixPair Matrix::toPair(uint8_t n)
{
    const int cols = 8;
    uint8_t row = n / cols;
    uint8_t col = n % cols;

    // Reverse the column index on every alternate row
    if (row % 2 == 1) {
        col = cols - 1 - col;
    }
    return MatrixPair(col, row);
}

void Matrix::drawPixelArt(const PixelArt &art)
{
    clear();
    for (int i = 0; i < 63; i++)
    {
        MatrixPair p = toPair(i);
        RGBTriple c = art.getPixelColor(p.row, p.col);
        setPixel(i, c.getR(), c.getG(), c.getB());
    }
    show();
}

void Matrix::drawTree()
{
    RGBTriple tree_green = RGBTriple(30,255,0);
    RGBTriple blank = RGBTriple();
    RGBTriple wood = RGBTriple(200,50, 0);
    const RGBTriple christmas_tree_colors[][8] = {
        { // R8
        blank, blank, blank, wood,
        wood, blank, blank, blank
        },
        { // R7
        tree_green, RGBTriple(255,30,40), tree_green, tree_green,
        tree_green, RGBTriple(50,0,255), tree_green, RGBTriple(255,0,0)
        },
        { // R6
        tree_green, tree_green, RGBTriple(100, 100, 50), tree_green,
        tree_green, tree_green, RGBTriple(0,0,255), tree_green
        },
        { // R5
        blank, RGBTriple(100, 0, 200), tree_green, RGBTriple(80,0,200),
        tree_green, tree_green, tree_green, blank
        },
        { // R4
        blank, blank, tree_green, tree_green,
        tree_green, RGBTriple(255,0,0), blank, blank
        },
        { // R3
        blank, blank, RGBTriple(130,40,255), tree_green,
        tree_green, tree_green, blank, blank
        },
        { // R2
        blank, blank, blank, tree_green,
        RGBTriple(255, 0, 100), blank, blank, blank
        },
        { // R1
        blank, blank, blank, tree_green,
        tree_green, blank, blank, blank
        }
    };
    Art8x8 christmas_tree = Art8x8(christmas_tree_colors);
    drawPixelArt(christmas_tree);
}

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

Matrix::~Matrix()
{
    matrix->clear();
    delete matrix;
}

void Matrix::clear() 
{
    matrix->clear();
}

void Matrix::show()
{
    matrix->show();
}

void Matrix::setPixel(uint8_t n, uint32_t c)
{
    matrix->setPixelColor(n, c);
}

void Matrix::setPixel(uint8_t n, uint8_t r, uint8_t g, uint8_t b)
{
    matrix->setPixelColor(n, r, g, b);
}

void Matrix::setPixel(uint8_t n, RGBTriple c)
{
    matrix->setPixelColor(n, c.getR(), c.getG(), c.getB());
}

// void Matrix::updatePixel(AnimationPixelUpdate pxUpdate)
// {
//     setPixel(toSingle(pxUpdate.getPost()), pxUpdate.c);
//     show();
// }

void Matrix::setCursor(int x, int y)
{
    matrix->setCursor(x, y);
}

void Matrix::print(const __FlashStringHelper * f)
{
    matrix->print(f);
}

int Matrix::width()
{
    return matrix->width();
}

void Matrix::fillScreen(uint16_t c)
{
    matrix->fillScreen(c);
}

void Matrix::setTextWrap(bool b)
{
    matrix->setTextWrap(b);
}

void Matrix::drawParticle(Particle& p)
{
    pxind n = toSingle(p.getX(), p.getY());
    setPixel(n, p.getRGB());
}

void fireworks()
{
    // Create base firework
    FireworkBase fw = FireworkBase(3, 0, RGBTriple(50, 50, 50), 4, 0, 1);
    
    do
    {
        drawParticle(fw);
        fw.step();
    } while !(fw.exploded());
    
    // Generate explosion particles
    uint8_t num_particles = random(3, 6);
    Particle* p_explosions = fw.generate_explosion(num_particles);
    for (uint8_t i; i < num_particles; i++)
    {
        p_explosions[i].setDX()
    }

    // Loop through till each particle is gone

    delete[] p_explosions;
}