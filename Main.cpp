#include <iostream>
#include <winscard.h>
#include "Commands.h"

SCARDCONTEXT applicationContext;
LONG rv, lReturn, lReturn2;
DWORD dwReaders = SCARD_AUTOALLOCATE, dwRecv, dwAP;
LPTSTR hmzReaders, kReader;
SCARDHANDLE     hCardHandle;



void Established() {
    rv = SCardEstablishContext(SCARD_SCOPE_SYSTEM, NULL, NULL, &applicationContext);
    if (rv == SCARD_E_NO_SERVICE)
    {
        std::cout << "SmartCard Service Not Running" << std::endl;
    }
    else if (rv != 0)
        std::cout << "SCardEstablishContext Error" << std::endl;
    else if (rv == SCARD_S_SUCCESS)
        std::cout << "Establishing Context" << std::endl;

}


void ListingReaders()
{
    lReturn = SCardListReaders(applicationContext, NULL, (LPTSTR)&hmzReaders, &dwReaders);
    switch (lReturn)
    {
    case SCARD_E_NO_READERS_AVAILABLE:
        printf("Reader is not in groups.\n");
        // Take appropriate action.
        // ...
        break;

    case SCARD_S_SUCCESS:
        // Do something with the multi string of readers.
        // Output the values.
        // A double-null terminates the list of values.
        kReader = hmzReaders;
        std::cout << "Card Readers" << std::endl;
        while ('\0' != *kReader)
        {
            // Display the value.
            printf("Reader: %s\n", kReader);
            // Advance to the next value.
            kReader = kReader + wcslen((wchar_t*)kReader) + 1;
        }
        // Free the memory.
        lReturn2 = SCardFreeMemory(applicationContext, hmzReaders);
        if (SCARD_S_SUCCESS != lReturn2)
            printf("Failed SCardFreeMemory\n");
        break;

    default:
        printf("Failed SCardListReaders\n");
        // Take appropriate action.
        // ...
        break;
    }
}

void Connecting()
{
    lReturn = SCardConnect(applicationContext,
        hmzReaders,
        SCARD_SHARE_SHARED,
        SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1,
        &hCardHandle,
        &dwAP);
    if (SCARD_S_SUCCESS != lReturn)
    {
        std::cout << "Failed SCardConnect" << std::endl;
        exit(1);  // Or other appropriate action.
    }
    else
        std::cout << "Connecting..." << std::endl;

    // Use the connection.
    // Display the active protocol.
    switch (dwAP)
    {
    case SCARD_PROTOCOL_T0:
        printf("Active protocol T0\n");
        break;

    case SCARD_PROTOCOL_T1:
        printf("Active protocol T1\n");
        break;

    case SCARD_PROTOCOL_UNDEFINED:
    default:
        printf("Active protocol unnegotiated or unknown\n");
        break;
    }

    // Remember to disconnect (by calling SCardDisconnect).
    // ...

}

void Select()
{
    //  Transmit the request.
    //  lReturn is of type LONG.
    //  hCardHandle was set by a previous call to SCardConnect.
    //  pbSend points to the buffer of bytes to send.
    //  dwSend is the DWORD value for the number of bytes to send.
    //  pbRecv points to the buffer for returned bytes.
    //  dwRecv is the DWORD value for the number of returned bytes.

    BYTE pbRecv[256];
    AID aids;
    APDU emv;

    dwRecv = sizeof(pbRecv);
    lReturn = SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID1, sizeof(aids.AID1), NULL, pbRecv, &dwRecv);
    if (pbRecv[1] == emv.File_NotFound[1])
    {
        SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID2, sizeof(aids.AID2), NULL, pbRecv, &dwRecv);
        if (pbRecv[1] == emv.File_NotFound[1])
        {
            SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID3, sizeof(aids.AID3), NULL, pbRecv, &dwRecv);
            if (pbRecv[1] == emv.File_NotFound[1])
            {
                SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID5, sizeof(aids.AID5), NULL, pbRecv, &dwRecv);
                if (pbRecv[1] == emv.File_NotFound[1])
                {
                    SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID5, sizeof(aids.AID5), NULL, pbRecv, &dwRecv);if (pbRecv[1] == emv.File_NotFound[1])
                    {
                        SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID6, sizeof(aids.AID6), NULL, pbRecv, &dwRecv);
                        if (pbRecv[1] == emv.File_NotFound[1])
                        {
                            SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID7, sizeof(aids.AID7), NULL, pbRecv, &dwRecv);
                            if (pbRecv[1] == emv.File_NotFound[1])
                            {
                                SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID8, sizeof(aids.AID8), NULL, pbRecv, &dwRecv);
                                if (pbRecv[1] == emv.File_NotFound[1])
                                {
                                    SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID9, sizeof(aids.AID9), NULL, pbRecv, &dwRecv);
                                    if (pbRecv[1] == emv.File_NotFound[1])
                                    {
                                        SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID10, sizeof(aids.AID10), NULL, pbRecv, &dwRecv);
                                        if (pbRecv[1] == emv.File_NotFound[1])
                                        {
                                            SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID11, sizeof(aids.AID11), NULL, pbRecv, &dwRecv);
                                            if (pbRecv[1] == emv.File_NotFound[1])
                                            {
                                                SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID12, sizeof(aids.AID12), NULL, pbRecv, &dwRecv);
                                                if (pbRecv[1] == emv.File_NotFound[1])
                                                {
                                                    SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID13, sizeof(aids.AID13), NULL, pbRecv, &dwRecv);
                                                    if (pbRecv[1] == emv.File_NotFound[1])
                                                    {
                                                        SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID14, sizeof(aids.AID14), NULL, pbRecv, &dwRecv);
                                                        if (pbRecv[1] == emv.File_NotFound[1])
                                                        {
                                                            SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID15, sizeof(aids.AID15), NULL, pbRecv, &dwRecv);if (pbRecv[1] == emv.File_NotFound[1])
                                                            {
                                                                SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID16, sizeof(aids.AID16), NULL, pbRecv, &dwRecv);
                                                                if (pbRecv[1] == emv.File_NotFound[1])
                                                                {
                                                                    SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID17, sizeof(aids.AID17), NULL, pbRecv, &dwRecv);
                                                                    if (pbRecv[1] == emv.File_NotFound[1])
                                                                    {
                                                                        SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID18, sizeof(aids.AID18), NULL, pbRecv, &dwRecv);
                                                                        if (pbRecv[1] == emv.File_NotFound[1])
                                                                        {
                                                                            SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID19, sizeof(aids.AID19), NULL, pbRecv, &dwRecv);
                                                                            if (pbRecv[1] == emv.File_NotFound[1])
                                                                            {
                                                                                SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID20, sizeof(aids.AID20), NULL, pbRecv, &dwRecv);
                                                                                if (pbRecv[1] == emv.File_NotFound[1])
                                                                                {
                                                                                    SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID21, sizeof(aids.AID21), NULL, pbRecv, &dwRecv);
                                                                                    if (pbRecv[1] == emv.File_NotFound[1])
                                                                                    {
                                                                                        SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID22, sizeof(aids.AID22), NULL, pbRecv, &dwRecv);
                                                                                        if (pbRecv[1] == emv.File_NotFound[1])
                                                                                        {
                                                                                            SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID23, sizeof(aids.AID23), NULL, pbRecv, &dwRecv);
                                                                                            if (pbRecv[1] == emv.File_NotFound[1])
                                                                                            {
                                                                                                SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID24, sizeof(aids.AID24), NULL, pbRecv, &dwRecv);
                                                                                                if (pbRecv[1] == emv.File_NotFound[1])
                                                                                                {
                                                                                                    SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID25, sizeof(aids.AID25), NULL, pbRecv, &dwRecv);
                                                                                                    if (pbRecv[1] == emv.File_NotFound[1])
                                                                                                    {
                                                                                                        SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID26, sizeof(aids.AID26), NULL, pbRecv, &dwRecv);
                                                                                                        if (pbRecv[1] == emv.File_NotFound[1])
                                                                                                        {
                                                                                                            SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID36, sizeof(aids.AID36), NULL, pbRecv, &dwRecv);
                                                                                                            if (pbRecv[1] == emv.File_NotFound[1])
                                                                                                            {
                                                                                                                SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID28, sizeof(aids.AID29), NULL, pbRecv, &dwRecv);
                                                                                                                if (pbRecv[1] == emv.File_NotFound[1])
                                                                                                                {
                                                                                                                    SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID30, sizeof(aids.AID30), NULL, pbRecv, &dwRecv);
                                                                                                                    if (pbRecv[1] == emv.File_NotFound[1])
                                                                                                                    {
                                                                                                                        SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID31, sizeof(aids.AID31), NULL, pbRecv, &dwRecv);
                                                                                                                        if (pbRecv[1] == emv.File_NotFound[1])
                                                                                                                        {
                                                                                                                            SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID32, sizeof(aids.AID32), NULL, pbRecv, &dwRecv);
                                                                                                                            if (pbRecv[1] == emv.File_NotFound[1])
                                                                                                                            {
                                                                                                                                SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID33, sizeof(aids.AID33), NULL, pbRecv, &dwRecv);
                                                                                                                                if (pbRecv[1] == emv.File_NotFound[1])
                                                                                                                                {
                                                                                                                                    SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID34, sizeof(aids.AID34), NULL, pbRecv, &dwRecv);
                                                                                                                                    if (pbRecv[1] == emv.File_NotFound[1])
                                                                                                                                    {
                                                                                                                                        SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID35, sizeof(aids.AID35), NULL, pbRecv, &dwRecv);
                                                                                                                                        if (pbRecv[1] == emv.File_NotFound[1])
                                                                                                                                        {
                                                                                                                                            SCardTransmit(hCardHandle, SCARD_PCI_T0, aids.AID36, sizeof(aids.AID36), NULL, pbRecv, &dwRecv);
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << "Response: ";
    for (unsigned int i = 0; i < dwRecv; i++)
        printf("%02X ", pbRecv[i]);
    std::cout << "\n";

}

void Get_Response()
{
    BYTE pbRecv[256];
    BYTE cmd[] = { 0x00, 0xC0, 0x00, 0x00, 0x2E };
    dwRecv = sizeof(pbRecv);
    lReturn = SCardTransmit(hCardHandle, SCARD_PCI_T0, cmd, sizeof(cmd), NULL, pbRecv, &dwRecv);
    std::cout << "Get Response: ";
    for (unsigned int i = 0; i < dwRecv; i++)
        printf("%02X ", pbRecv[i]);
    std::cout << "\n";

}

void Get_Response1()
{
    BYTE pbRecv[256];
    BYTE cmd[] = { 0x00, 0xC0, 0x00, 0x00, 0x08 };
    dwRecv = sizeof(pbRecv);
    lReturn = SCardTransmit(hCardHandle, SCARD_PCI_T0, cmd, sizeof(cmd), NULL, pbRecv, &dwRecv);
    std::cout << "Get Response: ";
    for (unsigned int i = 0; i < dwRecv; i++)
        printf("%02X ", pbRecv[i]);
    std::cout << "\n";

}

void Get_Proc()
{
    BYTE pbRecv[256];

    APDU emv;
    dwRecv = sizeof(pbRecv);
    lReturn = SCardTransmit(hCardHandle, SCARD_PCI_T0, emv.Get_Processing, sizeof(emv.Get_Processing), NULL, pbRecv, &dwRecv);
    std::cout << "Get Proccesing: ";
    for (unsigned int i = 0; i < dwRecv; i++)
        printf("%02X ", pbRecv[i]);
    std::cout << "\n";
}
void Read_Records()
{
    BYTE pbRecv[256];

    APDU emv;
    dwRecv = sizeof(pbRecv);
    lReturn = SCardTransmit(hCardHandle, SCARD_PCI_T0, emv.Read_Records, sizeof(emv.Read_Records), NULL, pbRecv, &dwRecv);
    std::cout << "Read Records: ";
    for (unsigned int i = 0; i < dwRecv; i++)
        printf("%02X ", pbRecv[i]);
    std::cout << "\n";

}

void releaseContext() {
    SCardReleaseContext(applicationContext);
}

int main() {

    Established();

    ListingReaders();

    Connecting();

    Select();
    Get_Response();
    Get_Proc();
    Get_Response1();
    Read_Records();;
    system("pause");
    releaseContext();
    return 0;
}
