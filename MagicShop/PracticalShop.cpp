//=============================================================================
//
// Shop Practical
//
// Begin by working on the TODOs in the Item class first. 
// Then, move on to Inventory.cpp
// Finally, complete the TODOs within the PracticalShop.cpp file
//
//=============================================================================

// TODO: When all work is done in Item.cpp and Inventory.cpp uncomment the following line.
#define INVENTORY

#include <iostream>
#include "Console.h"
#include "Utility.h"
#ifdef INVENTORY
#include "Inventory.cpp"
#endif
#include "ShopUtils.cpp"

using namespace std;

int main()
{
#ifdef INVENTORY
    Item HealthPotion;
    HealthPotion.SetName("Health Potion");
    HealthPotion.SetCost(10);
    Item MagicPotion("Magic Potion", 15);
    Item IronDagger("Iron Dagger", 30);
    Item WoodenClub("Wooden Club", 20);
    Item DaedricHelm("Daedric Helm", 120);
    Item MageRobe("Mage Robe", 50);
    Item AkaviriKatana("Akaviri Katana", 200);
    Item WabbaJack("Wabbajack", 500);

	Item PlayerStarterItems[] = { HealthPotion, HealthPotion, MagicPotion, WoodenClub };
	Item StoreStartingItems[] = { HealthPotion, MagicPotion, MagicPotion, IronDagger,
									DaedricHelm, MageRobe, AkaviriKatana, WabbaJack };
#endif

	// TODO: Define an Inventory object for the player, an Inventory object for the store. 
    Inventory playerInv;
    Inventory storeInv;
    string playerName;
    string defaultName = "Reclaimer";
    string noName = "";

	/* TODO: Prompt the user for their name
	 * ======================================
	 * Ask the user for their name and define a string for the
	 * name. Store their input in the string. If they entered 
	 * an empty string (e.g. "") assign them a default name.
	*/
    cout << "Welcome Newbie, what's your name? " << endl;
    getline(cin, playerName);
    //cin >> playerName;


    if (playerName.empty())
    {
        playerName = defaultName;
        //cout << "Hello, " << defaultName << "!" << endl;

    }
    else
        playerName = playerName;
    cout << "Hello, " << playerName << "!" << endl;
   
   


	// TODO: Use the SetGold method to give the player inventory 200 Gold.
    playerInv.SetGold(200);

	/* TODO: Call the AddItem method
	 * ================================
	 * Use the AddItem method to add each item in the
	 * PlayerStartingItems array to the player's inventory.
	 */
   
        playerInv.AddItem(StoreStartingItems[0]);
        playerInv.AddItem(StoreStartingItems[1]);
        playerInv.AddItem(StoreStartingItems[2]);
        playerInv.AddItem(StoreStartingItems[3]);
    
    

	// TODO: Use the SetGold method to give the store inventory 350 Gold.
    storeInv.SetGold(350);

    /* TODO: Call the AddItem method
	 * ================================
	 * Use the AddItem method to add each item in the
	 * StoreStartingItems array to the store's inventory.
	 */ 
   
   
    //Added my store's Items

        storeInv.AddItem(StoreStartingItems[0]);
        storeInv.AddItem(StoreStartingItems[1]);
        storeInv.AddItem(StoreStartingItems[2]);
        storeInv.AddItem(StoreStartingItems[3]);
        storeInv.AddItem(StoreStartingItems[4]);
        storeInv.AddItem(StoreStartingItems[5]);
        storeInv.AddItem(StoreStartingItems[6]);
        storeInv.AddItem(StoreStartingItems[7]);



	// TODO: Use the AddItem method to add each item in the StoreStartingItems array to the store's inventory.

  
    while (true)
    {
        int sel = 0;
        do
        {
            Console::Clear();

            /* TODO: Call the ShopUtils::ShowInventories method
             * =================================================
             * Call the ShowInventories method located within the
             * ShopUtils class and pass in the player's name,
             * the player's inventory and the store's inventory.
             */
            ShopUtils::ShowInventories(playerName, playerInv,  storeInv);


            Console::SetCursorPosition(5, 18);

            const std::string menu = "What would you like to do?\n1) Buy\n2) Sell\n3) Leave\n_\b";
            Console::Write(menu);

            sel = Utility::ReadInt();

        } while (!Utility::IsReadGood() || (sel < 1 || sel > 3));

        if (3 == sel)
            break;

        bool doBuy = false;
        if (1 == sel)
        {
            doBuy = true;
            
            
            
        }

        /* TODO: Call the ShopUtils::DoTransaction method
         * =============================================
         * Call the DoTransaction method locate within the
         * ShopUtils class and pass it the player's name,
         * the player's inventory, the store's inventory
         * and the doBuy variable.
         */		 
        ShopUtils::DoTransaction(playerName,  playerInv,  storeInv,  doBuy);
    }

    Console::Clear();
    Utility::WriteCentered("Thanks! Come back again!");
    Utility::WaitForEnterKey();
}
