#include <Windows.h>
#include <iostream>

int main( )
{
    HKEY key{ };
    const std::uint8_t admin_logon{ 1 };

    if ( RegOpenKeyExA( HKEY_LOCAL_MACHINE,
             "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon", 0,
             KEY_SET_VALUE, &key ) != ERROR_SUCCESS ||
         RegSetValueExA( key, "ForceUnlockLogon", false, REG_DWORD, &admin_logon,
             1 ) != ERROR_SUCCESS )
    {
        std::printf( "failed to set key. did you forget to run with administrator privileges?\n" );
        RegCloseKey( key );

        std::cin.get( );
        return 0;
    }

    std::printf( "process completed successfully.\n" );
    RegCloseKey( key );

    std::cin.get( );
    return 0;
}