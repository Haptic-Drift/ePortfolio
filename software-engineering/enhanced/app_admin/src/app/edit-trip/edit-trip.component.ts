import { Component } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';
import { ActivatedRoute, Router } from '@angular/router';
import { TripDataService } from '../trip-data.service';
import { Trip } from '../models/trip';

@Component({
  selector: 'app-edit-trip',
  standalone: true,
  imports: [CommonModule, FormsModule],
  templateUrl: './edit-trip.component.html',
  styleUrl: './edit-trip.component.css'
})
export class EditTripComponent {
  trip: Trip = {
    code: '',
    name: '',
    length: '',
    start: '',
    resort: '',
    perPerson: '',
    image: '',
    description: ''
  };

  originalCode = '';

  constructor(
    private route: ActivatedRoute,
    private router: Router,
    private tripDataService: TripDataService
  ) {
    const tripCode = this.route.snapshot.paramMap.get('code');
    if (tripCode) {
      this.originalCode = tripCode;
      this.tripDataService.getTrip(tripCode).subscribe({
        next: (data) => {
          this.trip = data;
        },
        error: (err) => {
          console.error('Error loading trip:', err);
        }
      });
    }
  }

  onSubmit(): void {
    this.tripDataService.updateTrip(this.originalCode, this.trip).subscribe({
      next: () => {
        this.router.navigate(['/']);
      },
      error: (err) => {
        console.error('Error updating trip:', err);
      }
    });
  }
}