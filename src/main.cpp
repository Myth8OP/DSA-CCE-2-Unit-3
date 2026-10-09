#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

#include "../include/SegmentList.hpp"
#include "../include/SpecStack.hpp"
#include "../include/BookingQueue.hpp"

void clearScreen() 
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void displayHeader() 
{
    clearScreen();
    std::cout << "     _   _   _ _____ ___  \n";
    std::cout << "    / \\ | | | |_   _/ _ \\ \n";
    std::cout << "   / _ \\| | | | | || | | |\n";
    std::cout << "  / ___ \\ |_| | | || |_| |\n";
    std::cout << " /_/   \\_\\___/  |_| \\___/ \n";
    std::cout << "\n";
    std::cout << "        AUTOMOTIVE SPECIFICATION BROWSER        \n";
    std::cout << "====================================================\n";
}

void initializeCatalog(SegmentList& catalog) 
{
    catalog.addSegment("Sedan");
    catalog.addSegment("SUV");
    catalog.addSegment("Hatchback");

    SegmentNode* sedanNode = catalog.findSegment("Sedan");
    if (sedanNode) 
    {
        sedanNode->models.addModel("Slavia", "Skoda");
        ModelNode* slavia = sedanNode->models.findModel("Slavia");
        if (slavia) 
        { 
            slavia->variants.addVariant("Active", "1.0 TSI", 115, 178, 11.53);
            slavia->variants.addVariant("Ambition", "1.0 TSI", 115, 178, 13.23);
            slavia->variants.addVariant("Style", "1.5 TSI", 150, 250, 17.23);
        }

        sedanNode->models.addModel("Virtus", "Volkswagen");
        ModelNode* virtus = sedanNode->models.findModel("Virtus");
        if (virtus) 
        {
            virtus->variants.addVariant("Comfortline", "1.0 TSI", 115, 178, 11.56);
            virtus->variants.addVariant("Highline", "1.0 TSI", 115, 178, 13.58);
            virtus->variants.addVariant("GT Plus", "1.5 TSI", 150, 250, 19.41);
        }
    }

    SegmentNode* hatchNode = catalog.findSegment("Hatchback");
    if (hatchNode) 
    {
        hatchNode->models.addModel("Altroz", "Tata");
        ModelNode* altroz = hatchNode->models.findModel("Altroz");
        if (altroz) 
        {
            altroz->variants.addVariant("XE", "1.2L Revotron", 88, 115, 6.60);
            altroz->variants.addVariant("XZ", "1.2L i-Turbo", 110, 140, 9.10);
            altroz->variants.addVariant("XZ Plus", "1.5L Revotorq", 90, 200, 10.74);
        }
    }

    SegmentNode* suvNode = catalog.findSegment("SUV");
    if (suvNode) 
    {
        suvNode->models.addModel("Creta", "Hyundai");
        ModelNode* creta = suvNode->models.findModel("Creta");
        if (creta) 
        {
            creta->variants.addVariant("E", "1.5L MPi", 115, 144, 11.00);
            creta->variants.addVariant("SX", "1.5L MPi", 115, 144, 15.30);
            creta->variants.addVariant("SX(O)", "1.5L Turbo", 160, 253, 20.15);
        }

        suvNode->models.addModel("XUV700", "Mahindra");
        ModelNode* xuv = suvNode->models.findModel("XUV700");
        if (xuv) 
        {
            xuv->variants.addVariant("MX", "2.0 TGDi", 200, 380, 14.03);
            xuv->variants.addVariant("AX5", "2.2 CRDi", 185, 420, 17.69);
            xuv->variants.addVariant("AX7 Luxury", "2.2 CRDi", 185, 450, 26.57);
        }

        suvNode->models.addModel("Safari", "Tata");
        ModelNode* safari = suvNode->models.findModel("Safari");
        if (safari) 
        {
            safari->variants.addVariant("Smart", "2.0 Kryotec", 167, 350, 13.40);
            safari->variants.addVariant("Adventure", "2.0 Kryotec", 167, 350, 19.99);
            safari->variants.addVariant("Accomplished", "2.0 Kryotec", 167, 350, 25.00);
        }
    }
}

void pauseMenu() 
{
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

int main() 
{
    SegmentList catalog;
    SpecStack historyStack;
    BookingQueue testDriveQueue;

    std::cout << "Initializing Dynamic Memory Structures...\n";
    initializeCatalog(catalog);

    int choice = 0;
    while (choice != 6) 
    {
        displayHeader();
        std::cout << " [1] View Vehicle Segments (Carousel)\n";
        std::cout << " [2] Browse Models in a Segment\n";
        std::cout << " [3] Compare Trims & Inspect Specs\n";
        std::cout << " [4] View Recently Browsed Trims (LIFO Stack)\n";
        std::cout << " [5] Manage Test Drives (FIFO Queue)\n";
        std::cout << " [6] Exit System\n";
        std::cout << "----------------------------------------------------\n";
        std::cout << "Enter command: ";
        
        if (!(std::cin >> choice)) 
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            choice = 0;
        }

        switch (choice) 
        {
            case 1:
                displayHeader();
                catalog.displaySegments();
                pauseMenu();
                break;
            case 2:
                displayHeader();
                {
                    std::string segName;
                    std::cout << "Enter Segment Name (e.g., Sedan, SUV): ";
                    std::cin >> segName;
                    std::cout << "Querying Circular Linked List...\n";
                    
                    SegmentNode* seg = catalog.findSegment(segName);
                    if (seg) seg->models.displayAllModels();
                    else std::cout << "Error: Segment not found.\n";
                }
                pauseMenu();
                break;
            case 3:
                displayHeader();
                {
                    std::string segName, modelName;
                    std::cout << "Enter Segment Name: "; std::cin >> segName;
                    SegmentNode* seg = catalog.findSegment(segName);
                    if (seg) {
                        std::cout << "Enter Model Name (e.g., Slavia): "; std::cin >> modelName;
                        std::cout << "Traversing Singly Linked List...\n";
                        
                        ModelNode* model = seg->models.findModel(modelName);
                        if (model) {
                            displayHeader();
                            model->variants.displayAllVariants();
                            VariantNode* currentTrim = model->variants.getHead(); 
                            
                            std::cout << "\n=== Viewing Specs for: " << currentTrim->trimName << " ===\n";
                            std::cout << std::left << std::setw(15) << "Engine Type:" << currentTrim->engineType << "\n";
                            std::cout << std::left << std::setw(15) << "Power Output:" << currentTrim->horsepower << " HP\n";
                            std::cout << std::left << std::setw(15) << "Torque:" << currentTrim->torqueNm << " Nm\n";
                            std::cout << std::left << std::setw(15) << "Ex-Showroom:" << "Rs " << currentTrim->priceLakhs << " Lakhs\n";
                            
                            historyStack.push(currentTrim);
                            
                            std::cout << "\nCalculating bidirectional upgrades via Doubly Linked List...\n";
                            model->variants.compareNext(currentTrim);
                        } 
                        else std::cout << "Error: Model not found.\n";
                    } 
                    else std::cout << "Error: Segment not found.\n";
                }
                pauseMenu();
                break;
            case 4:
                displayHeader();
                historyStack.displayHistory();
                pauseMenu();
                break;
            case 5:
                displayHeader();
                {
                    int qChoice;
                    std::cout << "[1] Add Booking | [2] Process Booking: ";
                    std::cin >> qChoice;
                    if (qChoice == 1) 
                    {
                        std::string name, car;
                        std::cout << "Enter Customer Name: "; std::cin >> name;
                        std::cout << "Enter Car Requested: "; std::cin >> car;
                        testDriveQueue.enqueue(name, car);
                    } 
                    else if (qChoice == 2) 
                    {
                        testDriveQueue.dequeue();
                    }
                }
                pauseMenu();
                break;
            case 6:
                displayHeader();
                std::cout << "Safely destroying nodes & freeing dynamic memory...\n";
                std::cout << "System shutdown complete. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid input. Please try again.\n";
                break;
        }
    }
    return 0;
}