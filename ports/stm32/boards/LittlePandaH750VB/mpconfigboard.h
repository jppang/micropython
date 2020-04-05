#define MICROPY_HW_BOARD_NAME       "LittlePandaH750"
#define MICROPY_HW_MCU_NAME         "STM32H750VB"

/* 启用 THREAD */ 
#define MICROPY_PY_THREAD           (1)

#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_ADC       (1)
#define MICROPY_HW_ENABLE_DAC       (1)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_ENABLE_SDCARD    (1)
#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_ENABLE_STORAGE   (1)

#define MICROPY_BOARD_EARLY_INIT    board_early_init
#define MICROPY_BOARD_ENTER_STOP    board_sleep(1);
#define MICROPY_BOARD_LEAVE_STOP    board_sleep(0);
#define MICROPY_BOARD_ENTER_STANDBY board_sleep(1);
//#define MICROPY_BOARD_SDCARD_POWER  mp_hal_pin_high(pyb_pin_EN_3V3);
void board_early_init(void);
void board_sleep(int value);


// The board has an 25MHz HSE, the following gives 480MHz CPU speed
#define MICROPY_HW_CLK_PLLM (25)
#define MICROPY_HW_CLK_PLLN (480)
#define MICROPY_HW_CLK_PLLP (2)
#define MICROPY_HW_CLK_PLLQ (4)
#define MICROPY_HW_CLK_PLLR (2)

// The board has a 32kHz crystal for the RTC
#define MICROPY_HW_RTC_USE_LSE      (1)
#define MICROPY_HW_RTC_USE_US       (0)
#define MICROPY_HW_RTC_USE_CALOUT   (1)

// The USB clock is set using PLL3
#define MICROPY_HW_CLK_PLL3M (25)
#define MICROPY_HW_CLK_PLL3N (120)
#define MICROPY_HW_CLK_PLL3P (2)
#define MICROPY_HW_CLK_PLL3Q (5)
#define MICROPY_HW_CLK_PLL3R (2)

// 4 wait states
#define MICROPY_HW_FLASH_LATENCY    FLASH_LATENCY_4

#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE    (0)

// 128MBit external QSPI flash, to be memory mapped
#define MICROPY_HW_QSPIFLASH_SIZE_BITS (128 * 1024 * 1024)
#define MICROPY_HW_QSPIFLASH_SIZE_BITS_LOG2 (27)
#define MICROPY_HW_QSPIFLASH_CS     (pin_B6)
#define MICROPY_HW_QSPIFLASH_SCK    (pin_B2)
#define MICROPY_HW_QSPIFLASH_IO0    (pin_D11)
#define MICROPY_HW_QSPIFLASH_IO1    (pin_D12)
#define MICROPY_HW_QSPIFLASH_IO2    (pin_E2)
#define MICROPY_HW_QSPIFLASH_IO3    (pin_D13)
// SPI flash #1, block device config
extern const struct _mp_spiflash_config_t spiflash_config;
extern struct _spi_bdev_t spi_bdev;

#define MICROPY_HW_BDEV_IOCTL(op, arg) ( \
    (op) == BDEV_IOCTL_NUM_BLOCKS ? (MICROPY_HW_QSPIFLASH_SIZE_BITS / 8 / FLASH_BLOCK_SIZE) : \
    (op) == BDEV_IOCTL_INIT ? spi_bdev_ioctl(&spi_bdev, (op), (uint32_t)&spiflash_config) : \
    spi_bdev_ioctl(&spi_bdev, (op), (arg)) \
)
#define MICROPY_HW_BDEV_READBLOCKS(dest, bl, n) spi_bdev_readblocks(&spi_bdev, (dest), (bl), (n))
#define MICROPY_HW_BDEV_WRITEBLOCKS(src, bl, n) spi_bdev_writeblocks(&spi_bdev, (src), (bl), (n))
#define MICROPY_HW_BDEV_SPIFLASH_EXTENDED (&spi_bdev) // for extended block protocol

// UART config
#define MICROPY_HW_UART1_TX         (pin_A9)
#define MICROPY_HW_UART1_RX         (pin_A10)
#define MICROPY_HW_UART2_TX         (pin_A2)
#define MICROPY_HW_UART2_RX         (pin_A3)
#define MICROPY_HW_UART3_TX         (pin_D8)
#define MICROPY_HW_UART3_RX         (pin_D9)
#define MICROPY_HW_UART4_TX         (pin_D1)
#define MICROPY_HW_UART4_RX         (pin_D0)
#define MICROPY_HW_UART6_TX         (pin_C6)
#define MICROPY_HW_UART6_RX         (pin_C7)
#define MICROPY_HW_UART7_TX         (pin_E7)
#define MICROPY_HW_UART7_RX         (pin_E8)


#define MICROPY_HW_UART_REPL        PYB_UART_1
#define MICROPY_HW_UART_REPL_BAUD   115200

// I2C busses
//#define MICROPY_HW_I2C1_SCL         (pin_B6)
//#define MICROPY_HW_I2C1_SDA         (pin_B7)
#define MICROPY_HW_I2C2_SCL         (pin_B10)
#define MICROPY_HW_I2C2_SDA         (pin_B11)
//#define MICROPY_HW_I2C4_SCL         (pin_D12)
//#define MICROPY_HW_I2C4_SDA         (pin_D13)

// SPI
#define MICROPY_HW_SPI1_NSS         (pin_A4)
#define MICROPY_HW_SPI1_SCK         (pin_A5)
#define MICROPY_HW_SPI1_MISO        (pin_A6)
#define MICROPY_HW_SPI1_MOSI        (pin_A7)
#define MICROPY_HW_SPI2_NSS         (pin_B12)
#define MICROPY_HW_SPI2_SCK         (pin_B13)
#define MICROPY_HW_SPI2_MISO        (pin_B14)
#define MICROPY_HW_SPI2_MOSI        (pin_B15)
#define MICROPY_HW_SPI3_NSS         (pin_B2)
#define MICROPY_HW_SPI3_SCK         (pin_B3)
#define MICROPY_HW_SPI3_MISO        (pin_B4)
#define MICROPY_HW_SPI3_MOSI        (pin_B5)
//#define MICROPY_HW_SPI4_NSS         (pin_E4)
//#define MICROPY_HW_SPI4_SCK         (pin_E2)
//#define MICROPY_HW_SPI4_MISO        (pin_E5)
//#define MICROPY_HW_SPI4_MOSI        (pin_E6)

// USRSW is pulled high. Pressing the button makes the input go low.
#define MICROPY_HW_USRSW_PIN        (pin_E2)
#define MICROPY_HW_USRSW_PULL       (GPIO_PULLUP)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_FALLING)
#define MICROPY_HW_USRSW_PRESSED    (0)

// LEDs
#define MICROPY_HW_LED1             (pin_E0)    // 
#define MICROPY_HW_LED2             (pin_E1)    //
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_low(pin))

// USB config
#define MICROPY_HW_USB_FS              (1)


// FDCAN bus
//#define MICROPY_HW_CAN1_NAME  "FDCAN1"
//#define MICROPY_HW_CAN1_TX    (pin_B13)
//#define MICROPY_HW_CAN1_RX    (pin_B12)

// SD card detect switch
#define MICROPY_HW_SDMMC1_CK                (pin_C12)
#define MICROPY_HW_SDMMC1_CMD               (pin_D2)
#define MICROPY_HW_SDMMC1_D0                (pin_C8)
#define MICROPY_HW_SDMMC1_D1                (pin_C9)
#define MICROPY_HW_SDMMC1_D2                (pin_C10)
#define MICROPY_HW_SDMMC1_D3                (pin_C11)
//#define MICROPY_HW_SDMMC2_CK                (pin_D6)
//#define MICROPY_HW_SDMMC2_CMD               (pin_D7)
//#define MICROPY_HW_SDMMC2_D0                (pin_B14)
//#define MICROPY_HW_SDMMC2_D1                (pin_B15)
//#define MICROPY_HW_SDMMC2_D2                (pin_B3)
//#define MICROPY_HW_SDMMC2_D3                (pin_B4)
//#define MICROPY_HW_SDCARD_DETECT_PIN        (pin_D3)
//#define MICROPY_HW_SDCARD_DETECT_PULL       (GPIO_PULLUP)
//#define MICROPY_HW_SDCARD_DETECT_PRESENT    (GPIO_PIN_RESET)
#define MICROPY_HW_SDCARD_MOUNT_AT_BOOT     (0)

// Ethernet via RMII (MDC define disabled for now until eth.c supports H7)
//#define MICROPY_HW_ETH_MDC          (pin_C1)
//#define MICROPY_HW_ETH_MDIO         (pin_A2)
//#define MICROPY_HW_ETH_RMII_REF_CLK (pin_A1)
//#define MICROPY_HW_ETH_RMII_CRS_DV  (pin_A7)
//#define MICROPY_HW_ETH_RMII_RXD0    (pin_C4)
//#define MICROPY_HW_ETH_RMII_RXD1    (pin_C5)
//#define MICROPY_HW_ETH_RMII_TX_EN   (pin_G11)
//#define MICROPY_HW_ETH_RMII_TXD0    (pin_G13)
//#define MICROPY_HW_ETH_RMII_TXD1    (pin_B13)
