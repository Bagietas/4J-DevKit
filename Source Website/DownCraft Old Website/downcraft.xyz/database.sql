-- phpMyAdmin SQL Dump
-- version 4.9.5
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : mar. 06 déc. 2022 à 23:47
-- Version du serveur :  10.5.16-MariaDB
-- Version de PHP : 7.3.32

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `id19856480_misaki_db`
--

-- --------------------------------------------------------

--
-- Structure de la table `apipremium`
--

CREATE TABLE `apipremium` (
  `accountID` int(11) NOT NULL,
  `userName` varchar(20) NOT NULL,
  `password` varchar(255) NOT NULL,
  `whitelist` varchar(500) NOT NULL DEFAULT 'RESET',
  `IP` varchar(16) NOT NULL DEFAULT 'RESET',
  `PSN` varchar(50) NOT NULL DEFAULT 'RESET',
  `isPremium` varchar(50) NOT NULL DEFAULT 'FREE',
  `API` varchar(50) NOT NULL DEFAULT 'NULL'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `logs_attach`
--

CREATE TABLE `logs_attach` (
  `id` int(11) NOT NULL,
  `log` varchar(8) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `skins`
--

CREATE TABLE `skins` (
  `id` int(11) NOT NULL,
  `code` varchar(8) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_access`
--

CREATE TABLE `sting_access` (
  `id` int(11) NOT NULL,
  `mysql_hôte` varchar(255) DEFAULT NULL,
  `mysql_user` varchar(255) DEFAULT NULL,
  `mysql_pass` varchar(255) DEFAULT NULL,
  `ftp_hôte` varchar(255) DEFAULT NULL,
  `ftp_user` varchar(255) DEFAULT NULL,
  `ftp_pass` varchar(255) DEFAULT NULL,
  `session_ip` varchar(255) DEFAULT NULL,
  `session_user` varchar(255) DEFAULT NULL,
  `session_pass` varchar(255) DEFAULT NULL,
  `session_expiration` datetime DEFAULT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `id_service` int(11) DEFAULT NULL,
  `session_état` enum('En attente','Active','Expiré','Résilié','Suspendu') DEFAULT NULL,
  `swf_variables` text DEFAULT NULL,
  `swf_text` text DEFAULT NULL,
  `swf_override_variables` text DEFAULT NULL,
  `swf_furnidata` text DEFAULT NULL,
  `swf_figuredata` text DEFAULT NULL,
  `swf_productdata` text DEFAULT NULL,
  `swf_game` text DEFAULT NULL,
  `swf_habbo_swf` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_adm_accounts`
--

CREATE TABLE `sting_adm_accounts` (
  `id` int(11) NOT NULL,
  `clef` int(11) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_badges`
--

CREATE TABLE `sting_badges` (
  `id` int(11) NOT NULL,
  `badge_id` varchar(255) DEFAULT NULL,
  `title` varchar(255) DEFAULT NULL,
  `description` varchar(255) DEFAULT NULL,
  `public` enum('0','1') DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_bans`
--

CREATE TABLE `sting_bans` (
  `id` int(11) NOT NULL,
  `username` varchar(30) DEFAULT NULL,
  `type` enum('Shoutbox','IP','Site&IP') DEFAULT NULL,
  `raison` text DEFAULT NULL,
  `ip` varchar(255) DEFAULT NULL,
  `date_expiration` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

-- --------------------------------------------------------

--
-- Structure de la table `sting_bots`
--

CREATE TABLE `sting_bots` (
  `id` int(11) NOT NULL,
  `phrase` text DEFAULT NULL,
  `type` enum('Bonjour','Heure','Recrutement') DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_codes_kdo`
--

CREATE TABLE `sting_codes_kdo` (
  `id` int(11) NOT NULL,
  `code` varchar(8) DEFAULT NULL,
  `gold` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_confirm_email`
--

CREATE TABLE `sting_confirm_email` (
  `id` int(11) NOT NULL,
  `email` varchar(255) DEFAULT NULL,
  `clef` int(11) DEFAULT NULL,
  `date` datetime DEFAULT NULL,
  `expiration` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_domains`
--

CREATE TABLE `sting_domains` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `extension` enum('.fr','.eu','.com','.net','.org','.xyz','.tk','.ml','.ga','.cf') NOT NULL,
  `état` enum('En attente','En cours de propagation','Actif','Expiré','Suspendu') NOT NULL,
  `date_order` datetime NOT NULL,
  `date_expiration` datetime NOT NULL,
  `dns_1` text NOT NULL,
  `dns_2` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_extensions`
--

CREATE TABLE `sting_extensions` (
  `id` int(11) NOT NULL,
  `extension` varchar(255) NOT NULL,
  `price` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_forum`
--

CREATE TABLE `sting_forum` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `sujet` varchar(50) DEFAULT NULL,
  `contenu` text DEFAULT NULL,
  `catégorie` enum('Discussion','Tutoriel','Aide','Annonce','Important') DEFAULT NULL,
  `état` enum('Ouvert','Épinglé','Fermé') DEFAULT NULL,
  `last_comment` datetime DEFAULT NULL,
  `date_open` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_forum_comments`
--

CREATE TABLE `sting_forum_comments` (
  `id` int(11) NOT NULL,
  `forum_id` int(11) DEFAULT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `comment` text DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_forum_likes`
--

CREATE TABLE `sting_forum_likes` (
  `id` int(11) NOT NULL,
  `forum_id` int(11) DEFAULT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_friends_requests`
--

CREATE TABLE `sting_friends_requests` (
  `id` int(11) NOT NULL,
  `demandeur_clef` int(11) DEFAULT NULL,
  `receveur_clef` int(11) DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_logs`
--

CREATE TABLE `sting_logs` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `action` text DEFAULT NULL,
  `ip` varchar(255) DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_logs_admin`
--

CREATE TABLE `sting_logs_admin` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `action` varchar(255) DEFAULT NULL,
  `ip` varchar(255) DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_logs_payments`
--

CREATE TABLE `sting_logs_payments` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) NOT NULL,
  `code` varchar(10) NOT NULL,
  `rate` varchar(255) DEFAULT NULL,
  `gold` int(11) NOT NULL,
  `payout` varchar(255) DEFAULT NULL,
  `ip` varchar(255) DEFAULT NULL,
  `navigator` text DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_lotos`
--

CREATE TABLE `sting_lotos` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `lot` text DEFAULT NULL,
  `date` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_notice`
--

CREATE TABLE `sting_notice` (
  `content` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_notifications`
--

CREATE TABLE `sting_notifications` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `avatar` text DEFAULT NULL,
  `content` text DEFAULT NULL,
  `open` enum('0','1') DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_options`
--

CREATE TABLE `sting_options` (
  `id` int(11) NOT NULL,
  `content` varchar(255) NOT NULL,
  `price` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_orders`
--

CREATE TABLE `sting_orders` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `extension` enum('.fr','.eu','.com','.net','.org','.tk','.ml','.xyz','.ga','.cf','.yourhabbo.fr') NOT NULL,
  `état` enum('En attente','Livraison en cours') NOT NULL,
  `plan` varchar(255) NOT NULL,
  `options` enum('Aucune','SWF','Session','SWF + Session') NOT NULL,
  `type` enum('Normal','Premium') DEFAULT NULL,
  `date_order` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_orders_options`
--

CREATE TABLE `sting_orders_options` (
  `id` int(11) NOT NULL,
  `id_service` int(11) DEFAULT NULL,
  `retro` varchar(255) DEFAULT NULL,
  `options` enum('SWF','Session') DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_plans`
--

CREATE TABLE `sting_plans` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `price` int(11) NOT NULL,
  `cms` varchar(255) NOT NULL,
  `émulateur` varchar(255) NOT NULL,
  `access` varchar(255) NOT NULL,
  `demo` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_profile_comments`
--

CREATE TABLE `sting_profile_comments` (
  `id` int(11) NOT NULL,
  `statut_id` int(11) DEFAULT NULL,
  `profile_clef` int(11) DEFAULT NULL,
  `user_clef` int(11) DEFAULT NULL,
  `content` text DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_profile_likes`
--

CREATE TABLE `sting_profile_likes` (
  `id` int(11) NOT NULL,
  `statut_id` int(11) DEFAULT NULL,
  `profile_clef` int(11) DEFAULT NULL,
  `user_clef` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_profile_messages`
--

CREATE TABLE `sting_profile_messages` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `profile_id` int(11) DEFAULT NULL,
  `message` text DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_profile_reports`
--

CREATE TABLE `sting_profile_reports` (
  `id` int(11) NOT NULL,
  `statut_id` int(11) DEFAULT NULL,
  `profile_clef` int(11) DEFAULT NULL,
  `user_clef` int(11) DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_pubs`
--

CREATE TABLE `sting_pubs` (
  `id` int(11) NOT NULL,
  `title` varchar(255) DEFAULT NULL,
  `description` text DEFAULT NULL,
  `bouton_name` varchar(255) DEFAULT NULL,
  `bouton_lien` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_repairs`
--

CREATE TABLE `sting_repairs` (
  `id` int(11) NOT NULL,
  `id_service` int(11) DEFAULT NULL,
  `type` enum('Redémarrage','CMS','BDD') DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_services`
--

CREATE TABLE `sting_services` (
  `id` int(11) NOT NULL,
  `name` varchar(25) NOT NULL,
  `extension` enum('.fr','.eu','.com','.net','.org','.tk','.ml','.xyz','.ga','.cf','.yourhabbo.fr') NOT NULL,
  `plan` varchar(255) NOT NULL,
  `état` enum('Actif','Expiré','Résilié','Suspendu') NOT NULL,
  `date_order` datetime DEFAULT NULL,
  `date_validation` datetime DEFAULT NULL,
  `date_expiration` datetime DEFAULT NULL,
  `options` enum('Aucune','SWF','Session','SWF + Session') DEFAULT NULL,
  `id_service` int(11) DEFAULT NULL,
  `clef_user` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_settings`
--

CREATE TABLE `sting_settings` (
  `name` varchar(30) NOT NULL,
  `description` text DEFAULT NULL,
  `maintenance` enum('0','1') DEFAULT NULL,
  `url` varchar(255) DEFAULT NULL,
  `register` enum('1','0') DEFAULT NULL,
  `recrutement` enum('0','1') DEFAULT NULL,
  `shoutbox` enum('1','2','3') DEFAULT NULL,
  `dedipass_public_key` varchar(255) DEFAULT NULL,
  `dedipass_private_key` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_shoutbox`
--

CREATE TABLE `sting_shoutbox` (
  `id` int(11) NOT NULL,
  `clef_user` varchar(255) DEFAULT NULL,
  `message` text DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_shoutbox_private`
--

CREATE TABLE `sting_shoutbox_private` (
  `id` int(11) NOT NULL,
  `clef_user` varchar(255) DEFAULT NULL,
  `message` text DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_subscriptions`
--

CREATE TABLE `sting_subscriptions` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `expiration` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_support`
--

CREATE TABLE `sting_support` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `sujet` varchar(45) DEFAULT NULL,
  `département` enum('Technique','Commercial') DEFAULT NULL,
  `contenu` text DEFAULT NULL,
  `état` enum('Ouvert','En attente','Répondu','Fermé') DEFAULT NULL,
  `date_open` datetime DEFAULT NULL,
  `last_response` datetime DEFAULT NULL,
  `last_clef` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_support_responses`
--

CREATE TABLE `sting_support_responses` (
  `id` int(11) NOT NULL,
  `ticket_id` int(11) DEFAULT NULL,
  `response` text DEFAULT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `date_response` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_updates`
--

CREATE TABLE `sting_updates` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `type_de_tâche` enum('Maintenance','Incident','Amélioration') DEFAULT NULL,
  `catégorie` enum('Site','Web','MySQL','VPS','Serveur dédié','Plesk') DEFAULT NULL,
  `système_exploitation` enum('Plesk','Linux','Windows','Proxmox') DEFAULT NULL,
  `sévérité` enum('Très basse','Basse','Moyenne','Haute','Très haute','Critique') DEFAULT NULL,
  `résumé` varchar(100) DEFAULT NULL,
  `état` enum('En cours','Terminé') DEFAULT NULL,
  `progression` int(11) DEFAULT NULL,
  `contenu` text DEFAULT NULL,
  `date` datetime DEFAULT NULL,
  `date_close` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_users`
--

CREATE TABLE `sting_users` (
  `id` int(11) NOT NULL,
  `username` varchar(50) NOT NULL,
  `password` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `clef` int(11) NOT NULL,
  `rank` enum('1','2','3','4','5','6','7','8','9','10') NOT NULL,
  `gold` int(11) NOT NULL,
  `avatar` text DEFAULT NULL,
  `registration_ip` varchar(255) DEFAULT NULL,
  `last_ip` varchar(255) DEFAULT NULL,
  `last_connection` datetime DEFAULT NULL,
  `registration` datetime DEFAULT NULL,
  `account_confirmed` enum('0','1','2') DEFAULT NULL,
  `real_password` varchar(255) NOT NULL DEFAULT 'RESET'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_users_badges`
--

CREATE TABLE `sting_users_badges` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `badge_id` varchar(255) DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_users_friends`
--

CREATE TABLE `sting_users_friends` (
  `id` int(11) NOT NULL,
  `user_clef` int(11) DEFAULT NULL,
  `friend_clef` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_users_online`
--

CREATE TABLE `sting_users_online` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `time` int(11) DEFAULT NULL,
  `last_connection` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_users_settings`
--

CREATE TABLE `sting_users_settings` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `facebook` text DEFAULT NULL,
  `twitter` text DEFAULT NULL,
  `snapchat` text DEFAULT NULL,
  `instagram` text DEFAULT NULL,
  `statut` enum('1','0') DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_view`
--

CREATE TABLE `sting_view` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `étoile` varchar(255) DEFAULT NULL,
  `comment` varchar(255) DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `sting_warnings`
--

CREATE TABLE `sting_warnings` (
  `id` int(11) NOT NULL,
  `clef_user` int(11) DEFAULT NULL,
  `points` int(11) DEFAULT NULL,
  `date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `apipremium`
--
ALTER TABLE `apipremium`
  ADD PRIMARY KEY (`accountID`);

--
-- Index pour la table `logs_attach`
--
ALTER TABLE `logs_attach`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `skins`
--
ALTER TABLE `skins`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_access`
--
ALTER TABLE `sting_access`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_adm_accounts`
--
ALTER TABLE `sting_adm_accounts`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_badges`
--
ALTER TABLE `sting_badges`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_bans`
--
ALTER TABLE `sting_bans`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_bots`
--
ALTER TABLE `sting_bots`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_codes_kdo`
--
ALTER TABLE `sting_codes_kdo`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_confirm_email`
--
ALTER TABLE `sting_confirm_email`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_domains`
--
ALTER TABLE `sting_domains`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_extensions`
--
ALTER TABLE `sting_extensions`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_forum`
--
ALTER TABLE `sting_forum`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_forum_comments`
--
ALTER TABLE `sting_forum_comments`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_forum_likes`
--
ALTER TABLE `sting_forum_likes`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_friends_requests`
--
ALTER TABLE `sting_friends_requests`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_logs`
--
ALTER TABLE `sting_logs`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_logs_admin`
--
ALTER TABLE `sting_logs_admin`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_logs_payments`
--
ALTER TABLE `sting_logs_payments`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_lotos`
--
ALTER TABLE `sting_lotos`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_notifications`
--
ALTER TABLE `sting_notifications`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_options`
--
ALTER TABLE `sting_options`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_orders`
--
ALTER TABLE `sting_orders`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_orders_options`
--
ALTER TABLE `sting_orders_options`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_plans`
--
ALTER TABLE `sting_plans`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_profile_comments`
--
ALTER TABLE `sting_profile_comments`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_profile_likes`
--
ALTER TABLE `sting_profile_likes`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_profile_messages`
--
ALTER TABLE `sting_profile_messages`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_profile_reports`
--
ALTER TABLE `sting_profile_reports`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_pubs`
--
ALTER TABLE `sting_pubs`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_repairs`
--
ALTER TABLE `sting_repairs`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_services`
--
ALTER TABLE `sting_services`
  ADD PRIMARY KEY (`id`) USING BTREE;

--
-- Index pour la table `sting_settings`
--
ALTER TABLE `sting_settings`
  ADD PRIMARY KEY (`name`);

--
-- Index pour la table `sting_shoutbox`
--
ALTER TABLE `sting_shoutbox`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_shoutbox_private`
--
ALTER TABLE `sting_shoutbox_private`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_subscriptions`
--
ALTER TABLE `sting_subscriptions`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_support`
--
ALTER TABLE `sting_support`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_support_responses`
--
ALTER TABLE `sting_support_responses`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_updates`
--
ALTER TABLE `sting_updates`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_users`
--
ALTER TABLE `sting_users`
  ADD PRIMARY KEY (`id`) USING BTREE;

--
-- Index pour la table `sting_users_badges`
--
ALTER TABLE `sting_users_badges`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_users_friends`
--
ALTER TABLE `sting_users_friends`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_users_online`
--
ALTER TABLE `sting_users_online`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_users_settings`
--
ALTER TABLE `sting_users_settings`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_view`
--
ALTER TABLE `sting_view`
  ADD PRIMARY KEY (`id`);

--
-- Index pour la table `sting_warnings`
--
ALTER TABLE `sting_warnings`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `apipremium`
--
ALTER TABLE `apipremium`
  MODIFY `accountID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `logs_attach`
--
ALTER TABLE `logs_attach`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `skins`
--
ALTER TABLE `skins`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_access`
--
ALTER TABLE `sting_access`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_adm_accounts`
--
ALTER TABLE `sting_adm_accounts`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_bans`
--
ALTER TABLE `sting_bans`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_bots`
--
ALTER TABLE `sting_bots`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_codes_kdo`
--
ALTER TABLE `sting_codes_kdo`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_confirm_email`
--
ALTER TABLE `sting_confirm_email`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_domains`
--
ALTER TABLE `sting_domains`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_extensions`
--
ALTER TABLE `sting_extensions`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_forum`
--
ALTER TABLE `sting_forum`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_forum_comments`
--
ALTER TABLE `sting_forum_comments`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_forum_likes`
--
ALTER TABLE `sting_forum_likes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_friends_requests`
--
ALTER TABLE `sting_friends_requests`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_logs`
--
ALTER TABLE `sting_logs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_logs_admin`
--
ALTER TABLE `sting_logs_admin`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_logs_payments`
--
ALTER TABLE `sting_logs_payments`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_lotos`
--
ALTER TABLE `sting_lotos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_notifications`
--
ALTER TABLE `sting_notifications`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_options`
--
ALTER TABLE `sting_options`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_orders`
--
ALTER TABLE `sting_orders`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_orders_options`
--
ALTER TABLE `sting_orders_options`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_plans`
--
ALTER TABLE `sting_plans`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_profile_comments`
--
ALTER TABLE `sting_profile_comments`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_profile_likes`
--
ALTER TABLE `sting_profile_likes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_profile_messages`
--
ALTER TABLE `sting_profile_messages`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_profile_reports`
--
ALTER TABLE `sting_profile_reports`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_repairs`
--
ALTER TABLE `sting_repairs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_services`
--
ALTER TABLE `sting_services`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_shoutbox`
--
ALTER TABLE `sting_shoutbox`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_shoutbox_private`
--
ALTER TABLE `sting_shoutbox_private`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_subscriptions`
--
ALTER TABLE `sting_subscriptions`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_support`
--
ALTER TABLE `sting_support`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_support_responses`
--
ALTER TABLE `sting_support_responses`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_updates`
--
ALTER TABLE `sting_updates`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_users`
--
ALTER TABLE `sting_users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_users_badges`
--
ALTER TABLE `sting_users_badges`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_users_friends`
--
ALTER TABLE `sting_users_friends`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_users_online`
--
ALTER TABLE `sting_users_online`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_users_settings`
--
ALTER TABLE `sting_users_settings`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_view`
--
ALTER TABLE `sting_view`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `sting_warnings`
--
ALTER TABLE `sting_warnings`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
