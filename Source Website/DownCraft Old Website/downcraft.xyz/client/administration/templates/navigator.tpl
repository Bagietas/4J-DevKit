<aside class="sidebar">
                <div class="scrollbar-inner">
                    <div class="user">
                        <div class="user__info" data-toggle="dropdown">
                            <img class="user__img" src="<?= $_SESSION['account']['avatar']; ?>" alt="">
                            <div>
                                <div class="user__name"><?= $_SESSION['account']['username']; ?></div>
                                <div class="user__email"><?= $Controller->Rank($_SESSION['account']['rank']); ?></div>
                            </div>
                        </div>

                        <div class="dropdown-menu">
                            <a class="dropdown-item" href="../?logout=1">Déconnexion</a>
                        </div>
                    </div>

                    <ul class="navigation">
                        <li class="navigation__<?php if($page == 'accueil') { echo 'active'; } ?>"><a href="index"><i class="zmdi zmdi-home"></i> Accueil</a></li>

						<?php if($_SESSION['account']['rank'] >= 8) { ?>
                        <li class="navigation__sub <?php if($page == 'website' OR $page == 'payment') { echo 'navigation__active'; } ?>">
                            <a href=""><i class="zmdi zmdi-settings"></i> Settings</a>

                            <ul>
                                <li class="@@sidebaractive"><a href="website">Website</a></li>
                            </ul>
                        </li>
						<li class="navigation__sub <?php if($page == 'paiement_h' OR $page == 'historique_g') { echo 'navigation__active'; } ?>">
                            <a href=""><i class="zmdi zmdi-assignment"></i> History</a>

                            <ul>
                                <li class="@@boxedactive"><a href="his_general">General</a></li>
								<li class="@@pactive"><a href="his_admin">Admin</a></li>
                            </ul>
                        </li>
						<li class="navigation__<?php if($page == 'update') { echo 'active'; } ?>">
                            <a href="updates"><i class="zmdi zmdi-refresh"></i> Update</a>
                        </li>
						<?php } ?>
						<?php if($_SESSION['account']['rank'] >= 6) { ?>
						<li class="navigation__sub <?php if($page == 'user') { echo 'navigation__active'; } ?>">
                            <a href=""><i class="zmdi zmdi-accounts"></i> Clients</a>

                            <ul>
                                <li class="@@sidebaractive"><a href="search">Search Users</a></li>
								<li class="@@pactive"><a href="ban">Ban</a></li>
                            </ul>
                        </li>
						<?php } ?>
						<li class="navigation__<?php if($page == 'tickets') { echo 'active'; } ?>"><a href="tickets"><i class="zmdi zmdi-ticket-star"></i> Tickets - Staff</a></li>
						<li class="navigation__sub <?php if($page == 'paiement_h' OR $page == 'historique_g') { echo 'navigation__active'; } ?>">
                        <li class="@@boxedactive"><a href="his_general"><i class="zmdi zmdi-assignment"></i> History Logs - Staff</a></li>
						<li class="@@boxedactive"><a href="ban"><i class="zmdi zmdi-accounts"></i> Ban - Staff</a></li>
                                    <li class="@@boxedactive"><a href="http://downcraft.pw/client/alert"><i class="zmdi zmdi-info"></i> News - Updates</a></li>
						<li class="@@boxedactive"><a href="premiumscan"><i class="zmdi zmdi-settings"></i> Premium Logs - Staff</a></li>
                    
                    </ul>
                </div>
            </aside>