#include <Matrix.h>
#include <Pixel.h>

Matrix::Matrix(uint16_t w, uint16_t h, uint8_t pin) 
    : 
    size(MatrixSize(w, h)), 
    matrix(new Adafruit_NeoMatrix(int(w), int(h), pin, NEO_MATRIX_BOTTOM + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE,
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


uint8_t Matrix::toSingle(const MatrixPair& p)
{
    uint8_t single;
    if (p.col % 2 == 0)
    {
        single = (p.col * 8) + p.row;
    }
    else 
    {
        single = ((p.col + 1) * 8) - 1; // Leftmost pixel
        single -= p.row; // Odd rows decrease left to right;
    }
    return single;
}

uint8_t Matrix::toSingle(pxind x, pxind y)
{
    uint8_t single;
    if (y % 2 == 0)
    {
        single = (y * 8) + x;
    }
    else 
    {
        single = ((y + 1) * 8) - 1; // Leftmost pixel
        single -= x; // Odd rows decrease left to right;
    }
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

void Matrix::_setPixel(uint8_t n, RGBTriple c)
{
    matrix->setPixelColor(n, c.getR(), c.getG(), c.getB());
}

void Matrix::setPixel(uint8_t n, uint32_t c)
{
    matrix->setPixelColor(n, c);
}

void Matrix::setPixel(uint8_t n, uint8_t r, uint8_t g, uint8_t b)
{
    _setPixel(n, RGBTriple(r,g,b));
}

void Matrix::setPixel(uint8_t n, RGBTriple c)
{
    _setPixel(n, c);
}

void Matrix::setPixel(uint8_t row, uint8_t col, uint32_t c)
{
    uint8_t n = toSingle(row, col);
    matrix->setPixelColor(n, c);
}

void Matrix::setPixel(uint8_t row, uint8_t col, uint8_t r, uint8_t g, uint8_t b)
{
    uint8_t n = toSingle(row, col);
    _setPixel(n, RGBTriple(r,g,b));
}

void Matrix::setPixel(uint8_t row, uint8_t col, RGBTriple c)
{
    uint8_t n = toSingle(row, col);
    _setPixel(n, c);
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

void Matrix::fireworks()
{
    // Create base firework
    pxind x_base = random(2, 6);
    RGBTriple color = RGBTriple(random(0, 200), random(0, 200), random(0, 200));
    FireworkBase fw = FireworkBase(x_base, 0, color, 4, 0, 1);
    // TODO deal with clearing particles
    do
    {
        clear();
        drawParticle(fw);
        show();
        fw.step();
        delay(200);
    } while (!(fw.exploded()));
    


    // Generate explosion particles
    //uint8_t num_particles = random(3, 6);
    uint8_t num_particles = 5;
    Particle* p_explosions = fw.generate_explosion(num_particles);
    //Particle p_explosions = Particle(4, 3, RGBTriple(50,50,50), 3, 1, 0);
    bool live;
    do 
    {
        live = false; // Reset live
        for (uint8_t i = 0; i < num_particles; i++)
        {
            if (p_explosions[i].getTTL() < 1) continue; // Live stays false if all particles are done
            live = true; // This particle is still alive
            drawParticle(p_explosions[i]);
            p_explosions[i].step();
            
            //Conditionally decremement dy for gravity effect
        }
        show();
        delay(100);
        clear();
    } while (live);
    // Loop through till each particle is gone

    delete[] p_explosions;
}

void Matrix::drawPixel(Pixel& p)
{
    setPixel(p.getX(), p.getY(), p.getRGB());
}

void Matrix::drawPixel(Pixel& p, RGBTriple c)
{
    setPixel(p.getX(), p.getY(), c);
}

// void Matrix::drawPixel(Pixel& p, uint32_t c)
// {
//     setPixel(p.getX(), p.getY(), c);
// }

void Matrix::drawPixelSet(PixelSet& set)
{
    for (auto p : set.px)
    {
        drawPixel(p);
    }
}

void Matrix::drawPixelSet(PixelSet& set, RGBTriple c)
{
    for (Pixel p : set.px)
    {
        drawPixel(p, c);
    }
}

void Matrix::rainbowGrad(uint8_t iterations = 3, uint64_t delay)
{
    uint8_t numSets = 8;
    MatrixPair pr1[1] = { MatrixPair(7,7) };
    MatrixPair pr2[3] = { MatrixPair(7,6), MatrixPair(6,6), MatrixPair(6,7) };
    MatrixPair pr3[7] = { MatrixPair(7,5), MatrixPair(7,4), MatrixPair(6,5), 
                        MatrixPair(5,5), MatrixPair(5,6), MatrixPair(5,7), 
                        MatrixPair(4,7) };
    MatrixPair pr4[10] = { MatrixPair(7,3), MatrixPair(6,3), MatrixPair(6,4), 
                        MatrixPair(5,4), MatrixPair(4,4), MatrixPair(4,5), 
                        MatrixPair(4,6), MatrixPair(3,6), MatrixPair(3,7),
                        MatrixPair(2,7) };
    MatrixPair pr5[12] = { MatrixPair(7,2), MatrixPair(6,2), MatrixPair(5,2), 
                        MatrixPair(5,3), MatrixPair(4,3), MatrixPair(3,3), 
                        MatrixPair(3,4), MatrixPair(3,5), MatrixPair(2,5),
                        MatrixPair(2,6), MatrixPair(1,6), MatrixPair(1,7) };
    MatrixPair pr6[14] = { MatrixPair(7,1), MatrixPair(6,1), MatrixPair(5,1), 
                        MatrixPair(4,1), MatrixPair(4,2), MatrixPair(3,2), 
                        MatrixPair(2,2), MatrixPair(2,3), MatrixPair(2,4),
                        MatrixPair(1,4), MatrixPair(1,5), MatrixPair(0,5),
                        MatrixPair(0,6), MatrixPair(0,7) };
    MatrixPair pr7[12] = { MatrixPair(7,0), MatrixPair(6,0), MatrixPair(5,0), 
                        MatrixPair(4,0), MatrixPair(3,0), MatrixPair(3,1), 
                        MatrixPair(2,1), MatrixPair(1,1), MatrixPair(1,2),
                        MatrixPair(1,3), MatrixPair(0,3), MatrixPair(0,4) };
    MatrixPair pr8[5] = { MatrixPair(2,0), MatrixPair(1,0), MatrixPair(0,0),
                        MatrixPair(0,1), MatrixPair(0,2) };
    PixelSet sets[numSets] = {
        PixelSet(pr1, 1),
        PixelSet(pr2, 3),
        PixelSet(pr3, 7),
        PixelSet(pr4, 10),
        PixelSet(pr5, 12),
        PixelSet(pr6, 14),
        PixelSet(pr7, 12),
        PixelSet(pr8, 5)      
    };

    ColorSetNode* head = rainbowColors();
    ColorSetNode* colors = head;

    while (1)
    {
        for (uint8_t i = 0; i < numSets; i++)
        {
            if (colors == nullptr)
            {
                colors = head;
                if (iterations--) return;
            }
            RGBTriple color = colors->c;
            colors = colors->next;
            drawPixelSet(sets[i], color);
        }
    }
}