# ATM System - Project Instructions

**Project**: KNPBANK ATM Simulation System (C++)
**Language**: Vietnamese (comments) + English (UI/output)
**Build**: `g++ -o atm.exe main.cpp ATM.cpp StartUp.cpp Shutdown.cpp Utils.cpp`
**Run**: `./atm.exe`

## Architecture

**Core modules**:
- `main.cpp` - Entry point, data arrays initialization
- `ATM.cpp/h` - Customer/admin menus, transaction logic (deposit/withdraw/transfer/balance/PIN)
- `StartUp.cpp/h` - Boot sequence, secret auth, account loading
- `Shutdown.cpp/h` - Save accounts/transactions, date increment
- `Utils.cpp/h` - Date handling, screen utils, hidden input, auth

**Data files**:
- `accounts.dat` - Account records (number, PIN, balance, lock status)
- `secret.dat` - Admin secret code (default: "KINAPU")
- `date.dat` - System date (simulated, increments on shutdown)
- `transactions_DD_MM_YYYY.dat` - Daily transaction logs

**Constants** (Utils.h):
- `MAX_ACCOUNTS = 100`
- `MAX_TRANS_PER_DAY = 5` (per customer per day)
- `MAX_TOTAL_TRANSACTIONS = 1000` (transaction log array size)
- `MAX_DAILY_AMOUNT = 20000000` VND (withdrawal/transfer limit)

## Business Rules

**Authentication**:
- Admin login: type "SECRET" at account prompt, enter secret code
- Customer login: 3 PIN attempts max → card locked on failure
- Locked cards require branch visit (no unlock in system)

**Transactions**:
- All amounts divisible by 50,000 VND
- Daily limit: 20M VND for withdraw/transfer combined
- Transfer: cannot send to self, recipient must exist
- Balance check counts as transaction (logged)
- Daily transaction count checked before deposit/withdraw/transfer/balance
- Transfer logs both TRANSFER (sender) and RECEIVE (recipient)

**Security**:
- PIN/secret input hidden (asterisks via `_getch()`)
- PIN change requires current PIN verification
- Secret code change requires current secret verification
- All PINs/secrets minimum 4 characters

**Date system**:
- Simulated date stored in `date.dat`
- Increments by 1 day on shutdown
- Transaction timestamps use current system date + fixed time "22:00:00"
- Daily counters/limits reset on new boot (not persisted)

## Code Style

**Naming**:
- Functions: camelCase (`displayMenu`, `findAccount`)
- Variables: camelCase (`accNums`, `totalAccs`)
- Constants: UPPER_SNAKE_CASE (`MAX_ACCOUNTS`)
- Files: PascalCase (ATM.cpp, StartUp.h)

**Patterns**:
- Arrays passed by reference with size parameter
- `silent` flag for internal saves (no console output)
- `waitForEnter()` after all user-facing operations
- `clearScreen()` before menu displays
- Transaction loop: validate → execute → log → update balance

**UI**:
- ASCII box borders (width: 99 chars)
- English-only menus/prompts (no Vietnamese in UI)
- Error messages: "Error: [reason]" format
- Success messages: "[Action] successful!" format

## Common Operations

**Add new transaction type**:
1. Add function in ATM.cpp (follow deposit/withdraw pattern)
2. Add case in customer menu loop (ATM.cpp:348-399)
3. Log transaction: `tAccs[tTotal] = accId; tTypes[tTotal] = "TYPE"; ...`
4. Increment `tTotal` and `dailyCnts[accIndex]`

**Modify validation**:
- Amount divisibility: ATM.cpp:92, 126, 385
- Daily limit check: ATM.cpp:131, 155
- PIN length: ATM.cpp:194

**Change UI text**:
- Welcome screen: ATM.cpp:13-29
- Customer menu: ATM.cpp:31-51
- Admin menu: ATM.cpp:53-68

## Testing

**Default accounts** (if accounts.dat missing):
- 1001/1234 - 5,000,000 VND
- 1002/2345 - 3,000,000 VND
- 1003/3456 - 10,000,000 VND
- 1004/4567 - 2,000,000 VND
- 1005/5678 - 7,500,000 VND

**Test scenarios**:
- PIN lockout: 3 wrong attempts → card retained
- Daily limit: withdraw 15M + withdraw 10M → second fails
- Transfer validation: self-transfer, non-existent recipient
- Amount validation: 75,000 VND (not divisible by 50k)
- Admin: shutdown saves data, date increments

## Build & Debug

**Compile**:
```bash
g++ -o atm.exe main.cpp ATM.cpp StartUp.cpp Shutdown.cpp Utils.cpp
```

**Clean build**:
```bash
rm -f atm.exe *.o
g++ -o atm.exe main.cpp ATM.cpp StartUp.cpp Shutdown.cpp Utils.cpp
```

**Debug flags**:
```bash
g++ -g -Wall -o atm.exe main.cpp ATM.cpp StartUp.cpp Shutdown.cpp Utils.cpp
```

**Windows-specific**:
- Uses `_getch()` from `<conio.h>` (non-portable)
- Clear screen: 50 newlines (not `system("cls")`)

## Constraints

**Do NOT**:
- Add external dependencies (keep stdlib only + conio.h)
- Change file formats without migration path
- Remove secret boot authentication
- Allow unlock of locked cards in ATM
- Use `system()` calls for security reasons
- Add Vietnamese text to UI (comments OK)

**Always**:
- Validate amount divisibility by 50,000
- Check daily limits before withdraw/transfer
- Save accounts.dat after lock status changes
- Log all transactions including balance checks
- Increment date on shutdown only
- Use `silent=true` for internal account updates

## Known Issues

**Current limitations**:
- Daily limits reset on reboot (not date-aware persistence)
- Transaction log append-only (no cleanup)
- No transaction history view for customers
- Fixed timestamp "22:00:00" (not real time)
- Windows-only (`_getch()` dependency)

**Future enhancements** (if requested):
- Persist daily limits across reboots
- Customer transaction history view
- Real-time timestamps
- Cross-platform input handling
- Account creation/deletion via admin
