-------------------------------------------------------------------------------
-- bfm_memory_wrapper.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

library plb_slave_bfm_v1_00_a;
use plb_slave_bfm_v1_00_a.All;

entity bfm_memory_wrapper is
  port (
    PLB_CLK : in std_logic;
    PLB_RESET : in std_logic;
    SYNCH_OUT : out std_logic_vector(0 to 31);
    SYNCH_IN : in std_logic_vector(0 to 31);
    PLB_PAValid : in std_logic;
    PLB_SAValid : in std_logic;
    PLB_rdPrim : in std_logic;
    PLB_wrPrim : in std_logic;
    PLB_masterID : in std_logic_vector(0 to 0);
    PLB_abort : in std_logic;
    PLB_busLock : in std_logic;
    PLB_RNW : in std_logic;
    PLB_BE : in std_logic_vector(0 to 7);
    PLB_msize : in std_logic_vector(0 to 1);
    PLB_size : in std_logic_vector(0 to 3);
    PLB_type : in std_logic_vector(0 to 2);
    PLB_compress : in std_logic;
    PLB_guarded : in std_logic;
    PLB_ordered : in std_logic;
    PLB_lockErr : in std_logic;
    PLB_ABus : in std_logic_vector(0 to 31);
    PLB_wrDBus : in std_logic_vector(0 to 63);
    PLB_wrBurst : in std_logic;
    PLB_rdBurst : in std_logic;
    PLB_pendReq : in std_logic;
    PLB_pendPri : in std_logic_vector(0 to 1);
    PLB_reqPri : in std_logic_vector(0 to 1);
    Sl_addrAck : out std_logic;
    Sl_ssize : out std_logic_vector(0 to 1);
    Sl_wait : out std_logic;
    Sl_rearbitrate : out std_logic;
    Sl_wrDAck : out std_logic;
    Sl_wrComp : out std_logic;
    Sl_wrBTerm : out std_logic;
    Sl_rdDBus : out std_logic_vector(0 to 63);
    Sl_rdWdAddr : out std_logic_vector(0 to 3);
    Sl_rdDAck : out std_logic;
    Sl_rdComp : out std_logic;
    Sl_rdBTerm : out std_logic;
    Sl_MBusy : out std_logic_vector(0 to 1);
    Sl_MErr : out std_logic_vector(0 to 1)
  );
end bfm_memory_wrapper;

architecture STRUCTURE of bfm_memory_wrapper is

  component plb_slave_bfm is
    generic (
      PLB_SLAVE_SIZE : std_logic_vector(0 to 1);
      PLB_SLAVE_NUM : std_logic_vector(0 to 3);
      PLB_SLAVE_ADDR_LO_0 : std_logic_vector(0 to 31);
      PLB_SLAVE_ADDR_HI_0 : std_logic_vector(0 to 31);
      PLB_SLAVE_ADDR_LO_1 : std_logic_vector(0 to 31);
      PLB_SLAVE_ADDR_HI_1 : std_logic_vector(0 to 31);
      C_PLB_DWIDTH : integer;
      C_PLB_NUM_MASTERS : integer;
      C_PLB_MID_WIDTH : integer
    );
    port (
      PLB_CLK : in std_logic;
      PLB_RESET : in std_logic;
      SYNCH_OUT : out std_logic_vector(0 to 31);
      SYNCH_IN : in std_logic_vector(0 to 31);
      PLB_PAValid : in std_logic;
      PLB_SAValid : in std_logic;
      PLB_rdPrim : in std_logic;
      PLB_wrPrim : in std_logic;
      PLB_masterID : in std_logic_vector(0 to C_PLB_MID_WIDTH-1);
      PLB_abort : in std_logic;
      PLB_busLock : in std_logic;
      PLB_RNW : in std_logic;
      PLB_BE : in std_logic_vector(0 to ((C_PLB_DWIDTH/8)-1));
      PLB_msize : in std_logic_vector(0 to 1);
      PLB_size : in std_logic_vector(0 to 3);
      PLB_type : in std_logic_vector(0 to 2);
      PLB_compress : in std_logic;
      PLB_guarded : in std_logic;
      PLB_ordered : in std_logic;
      PLB_lockErr : in std_logic;
      PLB_ABus : in std_logic_vector(0 to 31);
      PLB_wrDBus : in std_logic_vector(0 to (C_PLB_DWIDTH-1));
      PLB_wrBurst : in std_logic;
      PLB_rdBurst : in std_logic;
      PLB_pendReq : in std_logic;
      PLB_pendPri : in std_logic_vector(0 to 1);
      PLB_reqPri : in std_logic_vector(0 to 1);
      Sl_addrAck : out std_logic;
      Sl_ssize : out std_logic_vector(0 to 1);
      Sl_wait : out std_logic;
      Sl_rearbitrate : out std_logic;
      Sl_wrDAck : out std_logic;
      Sl_wrComp : out std_logic;
      Sl_wrBTerm : out std_logic;
      Sl_rdDBus : out std_logic_vector(0 to (C_PLB_DWIDTH-1));
      Sl_rdWdAddr : out std_logic_vector(0 to 3);
      Sl_rdDAck : out std_logic;
      Sl_rdComp : out std_logic;
      Sl_rdBTerm : out std_logic;
      Sl_MBusy : out std_logic_vector(0 to (C_PLB_NUM_MASTERS-1));
      Sl_MErr : out std_logic_vector(0 to (C_PLB_NUM_MASTERS-1))
    );
  end component;

begin

  bfm_memory : plb_slave_bfm
    generic map (
      PLB_SLAVE_SIZE => "01",
      PLB_SLAVE_NUM => "0000",
      PLB_SLAVE_ADDR_LO_0 => X"10000000",
      PLB_SLAVE_ADDR_HI_0 => X"1000ffff",
      PLB_SLAVE_ADDR_LO_1 => X"20000000",
      PLB_SLAVE_ADDR_HI_1 => X"2000ffff",
      C_PLB_DWIDTH => 64,
      C_PLB_NUM_MASTERS => 2,
      C_PLB_MID_WIDTH => 1
    )
    port map (
      PLB_CLK => PLB_CLK,
      PLB_RESET => PLB_RESET,
      SYNCH_OUT => SYNCH_OUT,
      SYNCH_IN => SYNCH_IN,
      PLB_PAValid => PLB_PAValid,
      PLB_SAValid => PLB_SAValid,
      PLB_rdPrim => PLB_rdPrim,
      PLB_wrPrim => PLB_wrPrim,
      PLB_masterID => PLB_masterID,
      PLB_abort => PLB_abort,
      PLB_busLock => PLB_busLock,
      PLB_RNW => PLB_RNW,
      PLB_BE => PLB_BE,
      PLB_msize => PLB_msize,
      PLB_size => PLB_size,
      PLB_type => PLB_type,
      PLB_compress => PLB_compress,
      PLB_guarded => PLB_guarded,
      PLB_ordered => PLB_ordered,
      PLB_lockErr => PLB_lockErr,
      PLB_ABus => PLB_ABus,
      PLB_wrDBus => PLB_wrDBus,
      PLB_wrBurst => PLB_wrBurst,
      PLB_rdBurst => PLB_rdBurst,
      PLB_pendReq => PLB_pendReq,
      PLB_pendPri => PLB_pendPri,
      PLB_reqPri => PLB_reqPri,
      Sl_addrAck => Sl_addrAck,
      Sl_ssize => Sl_ssize,
      Sl_wait => Sl_wait,
      Sl_rearbitrate => Sl_rearbitrate,
      Sl_wrDAck => Sl_wrDAck,
      Sl_wrComp => Sl_wrComp,
      Sl_wrBTerm => Sl_wrBTerm,
      Sl_rdDBus => Sl_rdDBus,
      Sl_rdWdAddr => Sl_rdWdAddr,
      Sl_rdDAck => Sl_rdDAck,
      Sl_rdComp => Sl_rdComp,
      Sl_rdBTerm => Sl_rdBTerm,
      Sl_MBusy => Sl_MBusy,
      Sl_MErr => Sl_MErr
    );

end architecture STRUCTURE;

