import { Component, Input } from '@angular/core';
import { CommonModule } from '@angular/common';
import { RouterModule } from '@angular/router';
import { Trip } from '../models/trip';
import { AuthenticationService } from '../authentication.service';

@Component({
  selector: 'app-trip-card',
  standalone: true,
  imports: [CommonModule, RouterModule],
  templateUrl: './trip-card.component.html',
  styleUrl: './trip-card.component.css'
})
export class TripCardComponent {
  @Input() trip!: Trip;

  constructor(public authService: AuthenticationService) {}
}