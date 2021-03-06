#pragma once
#include <bts/blockchain/address.hpp>
#include <bts/blockchain/transaction.hpp>
#include <bts/wallet/wallet.hpp>
#include <bts/dns/dns_db.hpp>

namespace bts { namespace dns {
    //namespace detail  { class dns_wallet_impl; }
    using namespace bts::blockchain;
    class dns_wallet : public bts::wallet::wallet
    {
        public:
            dns_wallet();
            ~dns_wallet();
            bts::blockchain::signed_transaction buy_domain(const std::string& name,
                                                        asset amount, dns_db& db);
            bts::blockchain::signed_transaction update_record(const std::string& name,
                                                    bts::blockchain::address domain_addr,
                                                    fc::variant value);
            bts::blockchain::signed_transaction sell_domain(const std::string&, 
                                            bts::blockchain::asset amount);
            // TODO put this in the parent wallet class?
            bts::blockchain::signed_transaction add_fee_and_sign(
                                                signed_transaction& trx,
                                                asset required_in,
                                                asset& total_in,
                                                std::unordered_set<address> req_sigs);

        protected:
            virtual bool scan_output( const bts::blockchain::trx_output& out,
                                      const bts::blockchain::output_reference& ref,
                                      const bts::wallet::output_index& oidx );

        private:
             //std::unique_ptr<detail::dns_wallet_impl> my;
     };

} } // bts::dns 
